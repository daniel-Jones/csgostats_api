# CS:GO stats api

Basic usage:
'''
#include <api.h>
[..]
api stats;
if (stats.setupstats("STEAM64ID"))
{
    qDebug() << "Hours in game" << stats.user.time_ingame;
    qDebug() << "Total kills" << stats.user.total_kills;
    qDebug() << "AK47 k/d ratio" << stats.user.weapons[0][5];
    }
[..] 
'''
See code for documentation.
