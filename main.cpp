#include <QCoreApplication>
#include <api.h>
#include <QDebug>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	api stats;
	if (stats.setupstats(argv[1]))
	{
		qDebug() << "Last match kills:" << stats.getlastmatchstat("last_kills");
	}
	return 0;
}
