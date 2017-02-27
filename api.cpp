#include "api.h"

api::api()
{
	qDebug() << "CS:GO stats api loaded";
}

bool api::setupstats(QString id)
{
	bool success;
	if (getfile(id))
		success = true;
	else
		success = false;
	if (success)
	{
		if (setupdata())
		{
			success = true;
		}
		else
		{
			success = false;
		}
	}
	return success;
}

bool api::getfile(QString id)
{
	bool success;
	QString url = "http://api.steampowered.com/ISteamUserStats/GetUserStatsForGame/v0002/?appid=730&key=FEBFDE46520663091143F867FEE39BFF&steamid=" + id;
	if (!QDir(loc).exists()) /* check if our application folder exists */
		QDir().mkdir(loc);
	if (QFile::exists(fileloc))
		QFile::remove(fileloc);
	QNetworkReply *reply = http.get(QNetworkRequest(url));
	QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
	loop.exec();
	QFile file(fileloc);
	file.open(QIODevice::WriteOnly);
	file.write(reply->readAll());
	delete reply;
	if (QFile::exists(fileloc) && file.size() > 0)
		success = true; /* file downloaded - could just be a blank file at this point */
	else
	{
		success = false; /* file did not download */
	}
	return success;
}

bool api::setupdata()
{
	bool success;
	for (int x = 0; x < 33; x++)
	{
		/* parse stats */
		user.weapons[x][2] = getdata("total_kills_" + user.weapons[x][0]);
		user.weapons[x][3] = getdata("total_shots_" + user.weapons[x][0]);
		user.weapons[x][4] = getdata("total_hits_" + user.weapons[x][0]);
		user.weapons[x][5] = QString::number(user.weapons[x][4].toFloat() / user.weapons[x][3].toFloat(), 'f', 2);
	}

	/*
	 * set data in user.maps
	 */
	for (int x = 0; x < 20; x++)
	{
		/* parse stats */
		user.maps[x][2] = getdata("total_rounds_map_" + user.maps[x][0] + '"');
		user.maps[x][3] = getdata("total_wins_map_" + user.maps[x][0] + '"');
		user.maps[x][4] = QString::number(user.maps[x][2].toInt() - user.maps[x][3].toInt());
		user.maps[x][5] = QString::number(user.maps[x][3].toFloat() / user.maps[x][2].toFloat(), 'f', 2);
	}
	/* time in game */
	user.time_ingame = getdata("total_time_played");
	user.time_ingame = QString::number(user.time_ingame.toInt() / 3600);
	/* mvp */
	user.mvp_count = getdata("total_mvps");
	/* total kills */
	user.total_kills = getdata("total_kill");
	/* total deaths */
	user.total_deaths = getdata("total_deaths");
	/* k/d ratio */
	user.kd_ratio = QString::number(user.total_kills.toFloat() / user.total_deaths.toFloat()).toFloat();
	success = true;
	return success;
}

QString api::getdata(QString option)
{
	/*
	 * this function parses csgodata.dat for stats
	 */
	QFile file(fileloc);
	if (file.open(QIODevice::ReadOnly))
	{
		QTextStream in(&file);
		while (!in.atEnd())
		{
			QString line = in.readLine();
			if (line.contains(option))
			{
				line = in.readLine();
				file.close();
				return line.split(": ")[1];
			}
		}
		file.close();
	}
	return "empty";
}
