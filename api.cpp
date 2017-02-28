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
		user.weapons[x][1] = getdata("total_kills_" + user.weapons[x][0]);
		user.weapons[x][2] = getdata("total_shots_" + user.weapons[x][0]);
		user.weapons[x][3] = getdata("total_hits_" + user.weapons[x][0]);
		user.weapons[x][4] = QString::number(user.weapons[x][3].toFloat() / user.weapons[x][2].toFloat(), 'f', 2);
	}

	/*
	 * set data in user.maps
	 */
	for (int x = 0; x < 20; x++)
	{
		/* parse stats */
		user.maps[x][1] = getdata("total_rounds_map_" + user.maps[x][0] + '"');
		user.maps[x][2] = getdata("total_wins_map_" + user.maps[x][0] + '"');
		user.maps[x][3] = QString::number(user.maps[x][1].toInt() - user.maps[x][2].toInt());
		user.maps[x][4] = QString::number(user.maps[x][2].toFloat() / user.maps[x][1].toFloat(), 'f', 2);
	}
	/* last match */
	user.lastmatch[0] = getdata("last_match_t_wins");
	user.lastmatch[1] = getdata("last_match_ct_wins");
	user.lastmatch[2] = getdata("last_match_wins");
	user.lastmatch[3] = getdata("last_match_max_players");
	user.lastmatch[4] = getdata("last_match_kills");
	user.lastmatch[5] = getdata("last_match_deaths");
	user.lastmatch[6] = getdata("last_match_mvps");
	user.lastmatch[7] = getdata("last_match_favweapon_id");
	user.lastmatch[8] = getdata("last_match_favweapon_shots");
	user.lastmatch[9] = getdata("last_match_favweapon_hits");
	user.lastmatch[10] = getdata("last_match_favweapon_kills");
	user.lastmatch[11] = getdata("last_match_damage");
	user.lastmatch[12] = getdata("last_match_money_spent");
	user.lastmatch[13] = getdata("last_match_dominations");
	user.lastmatch[14] = getdata("last_match_revenges");
	user.lastmatch[15] = getdata("last_match_contribution_score");
	user.lastmatch[16] = getdata("last_match_rounds");
	user.lastmatch[17] = getdata("last_match_gg_contribution_score");
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
