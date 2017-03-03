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
		QString getlastmatchstat(QString name);
		QString getmapstat(QString map, QString stat);
		QString getweaponstat(QString weapon, QString stat);
		/* this should all be private! */
		QString getdata(QString option);
		QString loc = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
		QString fileloc = loc + "/data";
		struct data
		{
			QString time_ingame;
			QString mvp_count;
			QString total_kills;
			QString total_deaths;
			float kd_ratio;
			/*
			   name | last match t wins | last match ct wins | last match wins | last match max players | last match kills
			   last match deaths | last mvps | last match fav weap id | last match fav weap shots | last match fav weap hits
			   last match fav weap kills | last match damage | last match money spent | last match dominations | last match revenges
			   last match contribution score | last match rounds | last match gg contribution score

			 */
			QString lastmatch[19] = {
				"", "", "", "", "",
				"", "", "", "", "",
				"", "", "", "", "",
				"", "", "", ""
			};
			QString lastkeys[19][2] = {
				{"name", "0"},
				{"last_t_wins", "1"},
				{"last_ct_wins", "2"},
				{"last_wins", "3"},
				{"last_max_players", "4"},
				{"last_kills", "5"},
				{"last_deaths", "6"},
				{"last_mvps", "7"},
				{"last_fav_weap", "8"},
				{"last_fav_weap_shots", "9"},
				{"last_fav_weap_hits", "10"},
				{"last_fav_weap_kills", "11"},
				{"last_damage", "12"},
				{"last_money_spent", "13"},
				{"last_dominations", "14"},
				{"last_last_revenges", "15"},
				{"last_contrib_score", "16"},
				{"last_rounds", "17"},
				{"last_gg_contrib_score", "18"},
			};
			QString mapkeys[20][2] = {
				{"cs_assault", ""},
				{"cs_italy", ""},
				{"cs_office", ""},
				{"de_aztec", ""},
				{"de_cbble", ""},
				{"de_dust2", ""},
				{"de_dust", ""},
				{"de_inferno", ""},
				{"de_nuke", ""},
				{"de_train", ""},
				{"de_lake", ""},
				{"de_stmarc", ""},
				{"de_safehouse", ""},
				{"ar_baggage", ""},
				{"ar_shoots", ""},
				{"de_bank", ""},
				{"ar_monas", ""},
				{"de_vertigo", ""},
				{"de_sugarcane", ""},
				{"cs_militia", ""},
			};

			QString maps[20][5] = {
				/* map name | rounds total | rounds win | rounds lost | win percent*/
				{"cs_assault", "", "", "", ""},
				{"cs_italy", "", "", "", ""},
				{"cs_office", "", "", "", ""},
				{"de_aztec", "", "", "", ""},
				{"de_cbble", "", "", "", ""},
				{"de_dust2", "", "", "", ""},
				{"de_dust", "", "", "", ""},
				{"de_inferno", "" "", "", ""},
				{"de_nuke", "", "", "", ""},
				{"de_train", "", "", "", ""},
				{"de_lake", "", "", "", ""},
				{"de_stmarc", "", "", "", ""},
				{"de_safehouse", "" "", "" , ""},
				{"ar_baggage", "", "", "", ""},
				{"ar_shoots", "", "", "", ""},
				{"de_bank", "", "", "", ""},
				{"ar_monas", "" "", "", ""},
				{"de_vertigo", "", "", "", ""},
				{"de_sugarcane", "", "", "", ""},
				{"cs_militia", "", "", "", ""},
			};
			QString weapons[33][5] = {
				/*weapon name | kills | shots | hits | ratio of hits to shots */
				{"ak47", "0", "0", "0", "0"},
				{"awp", "0", "0", "0", "0"},
				{"p90","0", "0", "0", "0"},
				{"deagle","0", "0", "0", "0"},
				{"m4", "0", "0", "0", "0"},
				{"knife", "0", "0", "0", "0"},
				{"fiveseven", "0", "0", "0", "0"},
				{"hkp2000", "0", "0", "0", "0"},
				{"glock", "0", "0", "0", "0"},
				{"p250", "0", "0", "0", "0"},
				{"mp7", "0", "0", "0", "0"},
				{"galil", "0", "0", "0", "0"},
				{"ump45", "0", "0", "0", "0"},
				{"tec9", "0", "0", "0", "0"},
				{"negev", "0", "0", "0", "0"},
				{"m249", "0", "0", "0", "0"},
				{"g3sg1", "0", "0", "0", "0"},
				{"scar20", "0", "0", "0", "0"},
				{"aug", "0", "0", "0", "0"},
				{"sg556", "0", "0", "0", "0"},
				{"nova", "0", "0", "0", "0"},
				{"sawedoff", "0", "0", "0", "0"},
				{"xm1014", "0", "0", "0", "0"},
				{"mag7", "0", "0", "0", "0"},
				{"mp9", "0", "0", "0", "0"},
				{"ssg08", "0", "0", "0", "0"},
				{"bizon", "0", "0", "0", "0"},
				{"mac10", "0", "0", "0", "0"},
				{"famas", "0", "0", "0", "0"},
				{"hegrenade", "0", "0", "0", "0"},
				{"elite", "0", "0", "0", "0"},
				{"taser", "0", "0", "0", "0"},
				{"molotov", "0", "0", "0", "0"},
			};
		} user;
	private:
		bool getfile(QString id);
		QNetworkAccessManager http;
		QEventLoop loop;
};

#endif // API_H
