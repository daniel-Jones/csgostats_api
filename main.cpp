#include <QCoreApplication>
#include <api.h>
#include <QDebug>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	api stats;
	if (stats.setupstats(argv[1]))
	{
		qDebug() << "stats setup correct";
		qDebug() << "hours in game:" << stats.user.time_ingame;
		qDebug() << "Total kills:" << stats.user.total_kills;
		qDebug() << "ak47 k/d ratio:" << stats.user.weapons[0][5];
	}
	return a.exec();
}
