#ifndef API_H
#define API_H
#include <QDebug>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QStandardPaths>
#include <QDir>

class api
{
	public:
		api();
		bool setupstats(QString id);
		bool setupdata();
		/* this should all be private! */
		QString getdata(QString option);
		QString loc = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
		QString fileloc = loc + "/data";
		/* remove image location at some point */
		struct data
		{
			QString time_ingame;
			QString mvp_count;
			QString total_kills;
			QString total_deaths;
			float kd_ratio;

			QString maps[20][6] = {
				/* map name | image location | rounds total | rounds win | rounds lost | win percent*/
				{"cs_assault", ":/maps/maps/cs_assault.png", "", "", ""},
				{"cs_italy", ":/maps/maps/cs_italy.png", "", "", "", ""},
				{"cs_office", ":/maps/maps/cs_office.png", "", "", "", ""},
				{"de_aztec", ":/maps/maps/de_aztec.png", "", "", "", ""},
				{"de_cbble", ":/maps/maps/de_cbble.png", "", "", "", ""},
				{"de_dust2", ":/maps/maps/de_dust2.png", "", "", "", ""},
				{"de_dust", ":/maps/maps/de_dust.png", "", "", "", ""},
				{"de_inferno", ":/maps/maps/de_inferno.png", "" "", "", ""},
				{"de_nuke", ":/maps/maps/de_nuke.png", "", "", "", ""},
				{"de_train", ":/maps/maps/de_train.png", "", "", "", ""},
				{"de_lake", ":/maps/maps/de_lake.png", "", "", "", ""},
				{"de_stmarc", ":/maps/maps/de_stmarc.png", "", "", "", ""},
				{"de_safehouse", ":/maps/maps/de_safehouse.png", "" "", "" , ""},
				{"ar_baggage", ":/maps/maps/ar_baggage.png", "", "", "", ""},
				{"ar_shoots", ":/maps/maps/ar_shoots.png", "", "", "", ""},
				{"de_bank", ":/maps/maps/de_bank.png", "", "", "", ""},
				{"ar_monas", ":/maps/maps/ar_monastery.png", "" "", "", ""},
				{"de_vertigo", ":/maps/maps/de_vertigo.png", "", "", "", ""},
				{"de_sugarcane", ":/maps/maps//de_sugarcane.png", "", "", "", ""},
				{"cs_militia", ":/maps/maps/cs_militia.png", "", "", "", ""},
			};
			QString weapons[33][6] = {
				/*weapon name | image location | kills | shots | hits | ratio of hits to shots */
				{"ak47", ":/weapons/weapons/weapon_ak47.png", "0", "0", "0", "0"},
				{"awp", ":/weapons/weapons/weapon_awp.png", "0", "0", "0", "0"},
				{"p90", ":/weapons/weapons/weapon_p90.png", "0", "0", "0", "0"},
				{"deagle", ":/weapons/weapons/weapon_deagle.png", "0", "0", "0", "0"},
				{"m4", ":/weapons/weapons/weapon_m4a1.png", "0", "0", "0", "0"},
				{"knife", ":/weapons/weapons/weapon_knife.png", "0", "0", "0", "0"},
				{"fiveseven", ":/weapons/weapons/weapon_fiveseven.png", "0", "0", "0", "0"},
				{"hkp2000", ":/weapons/weapons/weapon_hkp2000.png", "0", "0", "0", "0"},
				{"glock", ":/weapons/weapons/weapon_glock.png", "0", "0", "0", "0"},
				{"p250", ":/weapons/weapons/weapon_p250.png", "0", "0", "0", "0"},
				{"mp7", ":/weapons/weapons/weapon_mp7.png", "0", "0", "0", "0"},
				{"galil", ":/weapons/weapons/weapon_galil.png", "0", "0", "0", "0"},
				{"ump45", ":/weapons/weapons/weapon_ump45.png", "0", "0", "0", "0"},
				{"tec9", ":/weapons/weapons/weapon_tec9.png", "0", "0", "0", "0"},
				{"negev", ":/weapons/weapons/weapon_negev.png", "0", "0", "0", "0"},
				{"m249", ":/weapons/weapons/weapon_m249.png", "0", "0", "0", "0"},
				{"g3sg1", ":/weapons/weapons/weapon_g3sg1.png", "0", "0", "0", "0"},
				{"scar20", ":/weapons/weapons/weapon_scar20.png", "0", "0", "0", "0"},
				{"aug", ":/weapons/weapons/weapon_aug.png", "0", "0", "0", "0"},
				{"sg556", ":/weapons/weapons/weapon_sg556.png", "0", "0", "0", "0"},
				{"nova", ":/weapons/weapons/weapon_nova.png", "0", "0", "0", "0"},
				{"sawedoff", ":/weapons/weapons/weapon_sawedoff.png", "0", "0", "0", "0"},
				{"xm1014", ":/weapons/weapons/weapon_xm1014.png", "0", "0", "0", "0"},
				{"mag7", ":/weapons/weapons/weapon_mag7.png", "0", "0", "0", "0"},
				{"mp9", ":/weapons/weapons/weapon_mpn.png", "0", "0", "0", "0"},
				{"ssg08", ":/weapons/weapons/weapon_ssg08.png", "0", "0", "0", "0"},
				{"bizon", ":/weapons/weapons/weapon_bizon.png", "0", "0", "0", "0"},
				{"mac10", ":/weapons/weapons/weapon_mac10.png", "0", "0", "0", "0"},
				{"famas", ":/weapons/weapons/weapon_famas.png", "0", "0", "0", "0"},
				{"hegrenade", ":/weapons/weapons/weapon_hegrenade.png", "0", "0", "0", "0"},
				{"elite", ":/weapons/weapons/weapon_elite.png", "0", "0", "0", "0"},
				{"taser", ":/weapons/weapons/weapon_taser.png", "0", "0", "0", "0"},
				{"molotov", ":/weapons/weapons/weapon_molotov.png", "0", "0", "0", "0"},
			};
		} user;
	private:
		bool getfile(QString id);
		QNetworkAccessManager http;
		QEventLoop loop;
};

#endif // API_H
