#pragma once

//CONNECT 
//#define CONNECT "(DESCRIPTION = (ADDRESS = (PROTOCOL = TCP)(HOST = localhost)(PORT = 1521)) (CONNECT_DATA = (SERVER = DEDICATED) (SID = xe)))";
#define CONNECT "(DESCRIPTION = (ADDRESS = (PROTOCOL = TCP)(HOST = obelix.fri.uniza.sk)(PORT = 1521)) (CONNECT_DATA = (SERVER = DEDICATED) (SERVICE_NAME = orcl.fri.uniza.sk)))";

//SELECTS
#define LOAD_PARKS_ALL "select * from PR_PARKOVISKO"
#define LOAD_PARKS_NOT_DELETED "select * from PR_PARKOVISKO where ZMAZANY = 0 order by ID_PARKOVISKA"
#define LOAD_PARKS_DELETED "select * from PR_PARKOVISKO where ZMAZANY = 1"
#define LOAD_PARK(park_name) "select * from PR_PARKOVISKO where NAZOV = '" + park_name + "'"
#define LOAD_PARK_VIA_ID(parkId) "select * from PR_PARKOVISKO where ID_PARKOVISKA = " + parkId
#define LOAD_STALL(parkId, stallId) "select * from PR_PARKOVACIE_MIESTO where ID_PARKOVISKA = " + parkId + " and ID_PARK_MIESTA = " + stallId;
#define LOAD_STALL_FULL(parkId, stallId) "select * from PR_PARKOVACIE_MIESTO pm join PR_VSTUP v on pm.ID_PARKOVISKA = v.ID_PARKOVISKA where pm.ID_PARKOVISKA = " + parkId + " and v.ID_PARK_MIESTA = " + stallId;
#define LOAD_STALL_RESERVATION_INFO(parkId, stallId, from) "select v.SPZ, v.ZACIATOK, v.KONIEC from PR_PARKOVACIE_MIESTO pm join PR_VSTUP v on pm.ID_PARK_MIESTA = v.ID_PARK_MIESTA where pm.ID_PARKOVISKA = " + parkId + " and pm.ID_PARK_MIESTA = " + stallId + " and v.ZACIATOK <= to_date('" + from + "','DD.MM.YY HH24:MI:SS') and (v.KONIEC >= to_date('" + from + "','DD.MM.YY HH24:MI:SS') or v.KONIEC is null)";
#define LOAD_STALL_RESERVATION_INFO_CURRENT_TIME(parkId, stallId) "select v.SPZ, v.ZACIATOK, v.KONIEC from PR_PARKOVACIE_MIESTO pm join PR_VSTUP v on pm.ID_PARK_MIESTA = v.ID_PARK_MIESTA where pm.ID_PARKOVISKA = " + parkId + " and pm.ID_PARK_MIESTA = " + stallId + " and v.ZACIATOK <= sysdate and (v.KONIEC >= sysdate or v.KONIEC is null)";
#define LOAD_STALLS_FROM_RANGE(parkId, minX, maxX, minY, maxY) "select * from PR_PARKOVACIE_MIESTO where ID_PARKOVISKA = '" + parkId + "' and ZMAZANE = 0 and (X >= " + minX + " and X < " + maxX + ") and (Y >= " + minY + " and Y < " + maxY + ")";
#define LOAD_MAX_ID_FROM_PARKS "select MAX(ID_PARKOVISKA) from pr_parkovisko"
#define LOAD_MAX_ID_FROM_STALLS(parkId) "select MAX(ID_PARK_MIESTA) from PR_PARKOVACIE_MIESTO where ID_PARKOVISKA = " + parkId
#define LOAD_STALLS(parkId)  "select * from PR_PARKOVACIE_MIESTO where ID_PARKOVISKA = '" + parkId + "' and ZMAZANE = 0"
#define LOAD_DELETED_STALLS "select * from PR_PARKOVACIE_MIESTO where ZMAZANE = 1" 
#define CHECK_COUNT_STALLS_FROM_RANGE(parkId, minX, maxX, minY, maxY) "select count(*) from PR_PARKOVACIE_MIESTO where ID_PARKOVISKA = '" + parkId + "' and ZMAZANE = 0 and (X >= " + minX + " and X < " + maxX + ") and (Y >= " + minY + " and Y < " + maxY + ")";
#define CHECK_PLACE_FOR_STALL_HORIZONTAL(parkId, X, height, Y, width) "select count(*) from PR_PARKOVACIE_MIESTO where ID_PARKOVISKA = '" + parkId + "' and ZMAZANE = 0 and ((X + VELKOST_DLZKA >= " + X + " and X + VELKOST_DLZKA <= " + X + " + " + height + " and Y + VELKOST_SIRKA >= " + Y + " and Y + VELKOST_SIRKA <= " + Y + " + " + width + ") \
																																											or (" + X + " + " + height + " >= X and " + X + " + " + height + " <= X + VELKOST_DLZKA and Y + VELKOST_SIRKA >= " + Y + " and Y + VELKOST_SIRKA <= " + Y + " + " + width + ") \
																																											or (X + VELKOST_DLZKA >= " + X + " and X + VELKOST_DLZKA <= " + X + " + " + height + " and " + Y + " + " + width + " >= Y and " + Y + " + " + width + " <= Y + VELKOST_SIRKA) \
																																											or (" + X + " + " + height + " >= X and " + X + " + " + height + " <= X + VELKOST_DLZKA and " + Y + " + " + width + " >= Y and " + Y + " + " + width + " <=  Y + VELKOST_SIRKA))"
#define CHECK_PLACE_FOR_STALL_VERTICAL(parkId, X, height, Y, width) "select count(*) from PR_PARKOVACIE_MIESTO where ID_PARKOVISKA = '" + parkId + "' and ZMAZANE = 0 and ((X + VELKOST_SIRKA >= " + X + " and X + VELKOST_SIRKA <= " + X + " + " + width + " and Y + VELKOST_DLZKA >= " + Y + " and Y + VELKOST_DLZKA <= " + Y + " + " + height + ") \
																																											or (" + X + " + " + width + " >= X and " + X + " + " + width + " <= X + VELKOST_SIRKA and Y + VELKOST_DLZKA >= " + Y + " and Y + VELKOST_DLZKA <= " + Y + " + " + height + ") \
																																											or (X + VELKOST_SIRKA >= " + X + " and X + VELKOST_SIRKA <= " + X + " + " + width + " and " + Y + " + " + height + " >= Y and " + Y + " + " + height + " <= Y + VELKOST_DLZKA) \
																																											or (" + X + " + " + width + " >= X and " + X + " + " + width + " <= X + VELKOST_SIRKA and " + Y + " + " + height + " >= Y and " + Y + " + " + height + " <=  Y + VELKOST_DLZKA))"

#define LOAD_AUTO_COO_INFO "select ID_PARKOVISKA, sum(case when TYP_MIESTA = 0 and STAV = 0 then 1 else 0 end) as VolnyVolny, \
												  sum(case when TYP_MIESTA = 0 and STAV = 1 then 1 else 0 end) as VolnyObsa, \
												  sum(case when TYP_MIESTA = 1 and STAV = 0 then 1 else 0 end) as RezVolny, \
												  sum(case when TYP_MIESTA = 1 and STAV = 1 then 1 else 0 end) as RezObsa \
														from PR_PARKOVACIE_MIESTO join PR_PARKOVISKO using(ID_PARKOVISKA) where STATUS = 1 \
															group by ID_PARKOVISKA";
#define LOAD_MAX_ID_FREE_FREE_STALL(parkId) "select MAX(ID_PARK_MIESTA) from PR_PARKOVACIE_MIESTO where STAV = 0 and TYP_MIESTA = 0 and ID_PARKOVISKA = " + parkId;
#define LOAD_MAX_ID_RESERVE_FREE_STALL(parkId) "select MAX(ID_PARK_MIESTA) from PR_PARKOVACIE_MIESTO where STAV = 0 and TYP_MIESTA = 1 and ID_PARKOVISKA = " + parkId;

//SEARCHING
#define LOAD_FINDING_PARK_NAME_NOT_DELETED(word) "select * from PR_PARKOVISKO where NAZOV like '" + word + "%' and ZMAZANY = 0 order by ID_PARKOVISKA"
#define LOAD_FINDING_PARK_NAME_NOT_DELETED_ON(word) "select * from PR_PARKOVISKO where NAZOV like '" + word + "%' and ZMAZANY = 0 and STATUS = 1 order by ID_PARKOVISKA"
#define LOAD_FINDING_PARK_NAME_NOT_DELETED_OFF(word) "select * from PR_PARKOVISKO where NAZOV like '" + word + "%' and ZMAZANY = 0 and STATUS = 0 order by ID_PARKOVISKA"
#define LOAD_FINDING_PARK_ID_NOT_DELETED(word) "select * from PR_PARKOVISKO where ID_PARKOVISKA like '" + word + "%' and ZMAZANY = 0 order by ID_PARKOVISKA"
#define LOAD_FINDING_PARK_ID_NOT_DELETED_ON(word) "select * from PR_PARKOVISKO where ID_PARKOVISKA like '" + word + "%' and ZMAZANY = 0 and STATUS = 1 order by ID_PARKOVISKA"
#define LOAD_FINDING_PARK_ID_NOT_DELETED_OFF(word) "select * from PR_PARKOVISKO where ID_PARKOVISKA like '" + word + "%' and ZMAZANY = 0 and STATUS = 0 order by ID_PARKOVISKA"
#define LOAD_FINDING_PARK_NAME_DELETED(word) "select * from PR_PARKOVISKO where NAZOV like '" + word + "%' and ZMAZANY = 1 order by ID_PARKOVISKA"
#define LOAD_FINDING_PARK_ID_DELETED(word) "select * from PR_PARKOVISKO where ID_PARKOVISKA like '" + word + "%' and ZMAZANY = 1"
#define LOAD_FINDING_STALL_ID_DELETED(word) "select * from PR_PARKOVACIE_MIESTO where ID_PARK_MIESTA like '" + word + "%' and ZMAZANE = 1"
#define LOAD_FINDING_STALL_PARKID_DELETED(word) "select * from PR_PARKOVACIE_MIESTO where ID_PARKOVISKA like '" + word + "%' and ZMAZANE = 1"
#define LOAD_FINDING_STALL_STATE_DELETED(word) "select * from PR_PARKOVACIE_MIESTO where STAV like '" + word + "%' and ZMAZANE = 1"
#define LOAD_FINDING_STALL_TYPE_DELETED(word) "select * from PR_PARKOVACIE_MIESTO where TYP_MIESTA like '" + word + "%' and ZMAZANE = 1"
#define LOAD_FINDING_STALL_X_DELETED(word) "select * from PR_PARKOVACIE_MIESTO where X like '" + word + "%' and ZMAZANE = 1"
#define LOAD_FINDING_STALL_Y_DELETED(word) "select * from PR_PARKOVACIE_MIESTO where Y like '" + word + "%' and ZMAZANE = 1"

#define LOAD_STALLS_FROM_TIME_RESERVED_RESERVE(parkId, minX, maxX, minY, maxY, from) "select * from PR_PARKOVACIE_MIESTO pm join PR_VSTUP v on pm.ID_PARKOVISKA = v.ID_PARKOVISKA join PR_REZERVACIA re on re.spz = v.spz \
																				where pm.ZMAZANE = 0 and pm.ID_PARK_MIESTA = v.ID_PARK_MIESTA and v.ZACIATOK <= to_date('" + from + "','DD.MM.YY HH24:MI:SS') \
																				and (v.KONIEC >= to_date('" + from + "','DD.MM.YY HH24:MI:SS') or v.KONIEC is null) \
																				and pm.ID_PARKOVISKA = " + parkId + " and (pm.X >= " + minX + " and pm.X < " + maxX + ") and (pm.Y >= " + minY + " and pm.Y < " + maxY + ") \
																				and (re.ZACIATOK >= (v.ZACIATOK - 0.02083333) and (re.ZACIATOK <= v.KONIEC or v.KONIEC is null))";

#define LOAD_STALLS_FROM_TIME_RESERVED_FREE(parkId, minX, maxX, minY, maxY, from) "select * from PR_PARKOVACIE_MIESTO pm join PR_VSTUP v on pm.ID_PARKOVISKA = v.ID_PARKOVISKA \
																				where pm.ZMAZANE = 0 and pm.ID_PARK_MIESTA = v.ID_PARK_MIESTA and v.ZACIATOK <= to_date('" + from + "','DD.MM.YY HH24:MI:SS') \
																				and (v.KONIEC >= to_date('" + from + "','DD.MM.YY HH24:MI:SS') or v.KONIEC is null) \
																				and pm.ID_PARKOVISKA = " + parkId + " and (pm.X >= " + minX + " and pm.X < " + maxX + ") and (pm.Y >= " + minY + " and pm.Y < " + maxY + ") \
																				and not exists (select * from PR_REZERVACIA re where v.spz = re.spz \
																									and (re.ZACIATOK >= (v.ZACIATOK - 0.02083333) and (re.ZACIATOK <= v.KONIEC or v.KONIEC is null)))";

#define LOAD_STALLS_FROM_TIME_FREE_FREE(parkId, minX, maxX, minY, maxY, from) "select * from PR_PARKOVACIE_MIESTO pm where pm.ZMAZANE = 0 \
																				and pm.ID_PARKOVISKA = " + parkId + " and (pm.X >= " + minX + " and pm.X < " + maxX + ") and (pm.Y >= " + minY + " and pm.Y < " + maxY + ") \
																				and not exists (select * from PR_VSTUP v where \
																									pm.ID_PARK_MIESTA = v.ID_PARK_MIESTA and v.ZACIATOK <= to_date('" + from + "','DD.MM.YY HH24:MI:SS') \
																									and (v.KONIEC >= to_date('" + from + "','DD.MM.YY HH24:MI:SS') or v.KONIEC is null))"; 



//UPDATES
#define CHANGE_STALL_TYPE(park_id, stall_id, new_type) "update PR_PARKOVACIE_MIESTO set TYP_MIESTA = " + new_type + ", POSLEDNA_ZMENA = sysdate, TYP_AKCIE = 2 where ID_PARKOVISKA = " + parkId + " and ID_PARK_MIESTA = " + stall_id;
#define CHANGE_STALL_TO_DELETED(parkId, stallId) "update PR_PARKOVACIE_MIESTO set ZMAZANE = 1, POSLEDNA_ZMENA = sysdate, TYP_AKCIE = 2 where ID_PARKOVISKA = " + parkId + " and ID_PARK_MIESTA = " + stallId 
#define CHANGE_SYNC_VERSION(newVersion) "update SYNC_VERZIE set VERZIA = " + newVersion + " where id = 1";
#define CHANGE_SYNC_DATA_STALLS_UPDATE(parkId, newVersion) "update SYNC_VERZIE_P_MIESTA set VERZIA = " + newVersion + ", ZMENA_UPDATE = sysdate where ID_PARKOVISKA = " + parkId
#define CHANGE_SYNC_DATA_STALLS_INSERT(parkId, newVersion) "update SYNC_VERZIE_P_MIESTA set VERZIA = " + newVersion + ", ZMENA_INSERT = sysdate where ID_PARKOVISKA = " + parkId;
#define CHANGE_TIMESTAMP_PR_PARKOVISKO_INSERT_NOW "update SYNC_VERZIE set PR_PARKOVISKO_INSERT = sysdate where id = 1";
#define CHANGE_TIMESTAMP_PR_PARKOVISKO_UPDATE_NOW "update SYNC_VERZIE set PR_PARKOVISKO_UPDATE = sysdate where id = 1";
#define CHANGE_TIMESTAMP_PR_PARKOVISKO_DELETE_NOW "update SYNC_VERZIE set PR_PARKOVISKO_DELETE = sysdate where id = 1";
#define CHANGE_PARK_NAME(newName, parkId) "update PR_PARKOVISKO set NAZOV = '" + newName + "', POSLEDNA_ZMENA = sysdate, TYP_AKCIE = 2 where ID_PARKOVISKA = " + parkId;
#define CHANGE_PARK_ADRESS(newAdress, parkId) "update PR_PARKOVISKO set ADRESA = '" + newAdress + "', POSLEDNA_ZMENA = sysdate, TYP_AKCIE = 2 where ID_PARKOVISKA = " + parkId;
#define CHANGE_PARK_TO_DELETED(parkId) "update PR_PARKOVISKO set ZMAZANY = 1, POSLEDNA_ZMENA = sysdate, TYP_AKCIE = 3 where ID_PARKOVISKA = " + parkId
#define CHANGE_PARK_TO_NOT_DELETED(parkId) "update PR_PARKOVISKO set ZMAZANY = 0, POSLEDNA_ZMENA = sysdate, TYP_AKCIE = 3 where ID_PARKOVISKA = " + parkId
#define CHANGE_PARK_CAPACITY(parkId, newCapacity) "update PR_PARKOVISKO set MAX_KAPACITA = " + newCapacity + " where ID_PARKOVISKA = " + parkId
#define CHANGE_PARK_STATUS(parkId, newStatus) "update PR_PARKOVISKO set STATUS = " + newStatus + ", POSLEDNA_ZMENA = sysdate, TYP_AKCIE = 2 where ID_PARKOVISKA = " + parkId
#define CHANGE_PARK_LATITUDE(parkId, newLatitude) "update PR_PARKOVISKO set ZEM_SIRKA = " + newLatitude + ", POSLEDNA_ZMENA = sysdate, TYP_AKCIE = 2 where ID_PARKOVISKA = " + parkId
#define CHANGE_PARK_LONGTITUDE(parkId, newLongtitude) "update PR_PARKOVISKO set ZEM_DLZKA = " + newLongtitude + ", POSLEDNA_ZMENA = sysdate, TYP_AKCIE = 2 where ID_PARKOVISKA = " + parkId


//INSERT
#define INSERT_PARK(id_parkoviska, park_adress, park_capacity, park_name, x, y) "insert into PR_PARKOVISKO(ID_PARKOVISKA, ADRESA, MAX_KAPACITA, POSLEDNA_ZMENA, TYP_AKCIE, NAZOV, ZMAZANY, STATUS, ZEM_SIRKA, ZEM_DLZKA) values(" + id_parkoviska + ", '" + park_adress + "', '" + park_capacity + "', sysdate, 1, '" + park_name + "', 0, 0, '"+ x + "', '" + y + "')"
#define INSERT_STALL(stallId, parkId, X, Y, orientation, height, width) "insert into PR_PARKOVACIE_MIESTO(ID_PARK_MIESTA, ID_PARKOVISKA, STAV, TYP_MIESTA, X, Y, POSLEDNA_ZMENA, TYP_AKCIE, ZMAZANE, ORIENTACIA, VELKOST_DLZKA, VELKOST_SIRKA) values(" + stallId + ", " + parkId + ", 0, 2, " + X + ", " + Y + ", sysdate, 1, 0, " + orientation + ", " + height + ", " + width + ")"
#define INSERT_STALL_SYNC_DATA(parkId) "insert into SYNC_VERZIE_P_MIESTA(ID_PARKOVISKA, VERZIA, ZMENA_UPDATE, ZMENA_INSERT) values(" + parkId + ", 1, sysdate, sysdate)"

//SYNCHRONIZATION
#define LOAD_CURRENT_SYNC_VER "select VERZIA from SYNC_VERZIE where ID = 1"	
#define LOAD_CURRENT_SYNC_VER_STALLS(parkId) "select VERZIA from SYNC_VERZIE_P_MIESTA where ID_PARKOVISKA = " + parkId	
#define LOAD_PARKS_INSERT_TIMESTAMP "select PR_PARKOVISKO_INSERT from SYNC_VERZIE where ID = 1"
#define LOAD_PARKS_UPDATE_TIMESTAMP "select PR_PARKOVISKO_UPDATE from SYNC_VERZIE where ID = 1"
#define LOAD_PARKS_DELETE_TIMESTAMP "select PR_PARKOVISKO_DELETE from SYNC_VERZIE where ID = 1"
#define LOAD_STALLS_UPDATE_TIMESTAMP(parkId) "select ZMENA_UPDATE from SYNC_VERZIE_P_MIESTA where ID_PARKOVISKA = " + parkId
#define LOAD_STALLS_INSERT_TIMESTAMP(parkId) "select ZMENA_INSERT from SYNC_VERZIE_P_MIESTA where ID_PARKOVISKA = " + parkId
#define SYNC_LOAD_PARKS_INSERT(parkTimeStamp) "select * from PR_PARKOVISKO where (POSLEDNA_ZMENA > to_date('" + parkTimeStamp + "','DD.MM.YY HH24:MI:SS')) AND (TYP_AKCIE = 1)"
#define SYNC_LOAD_PARKS_UPDATE(parkTimeStamp) "select * from PR_PARKOVISKO where (POSLEDNA_ZMENA > to_date('" + parkTimeStamp + "','DD.MM.YY HH24:MI:SS')) AND (TYP_AKCIE = 2)"
#define SYNC_LOAD_STALLS_UPDATE(stallsTimeStamp, parkId, minX, maxX, minY, maxY) "select * from PR_PARKOVACIE_MIESTO where (POSLEDNA_ZMENA > to_date('" + stallsTimeStamp + "','DD.MM.YY HH24:MI:SS')) AND (TYP_AKCIE = 2) AND ID_PARKOVISKA = " + parkId + " and (X >= " + minX + " and X < " + maxX + ") and (Y >= " + minY + " and Y < " + maxY + ")";
#define SYNC_LOAD_STALLS_INSERT(stallsTimeStamp, parkId, minX, maxX, minY, maxY) "select * from PR_PARKOVACIE_MIESTO where (POSLEDNA_ZMENA > to_date('" + stallsTimeStamp + "','DD.MM.YY HH24:MI:SS')) AND (TYP_AKCIE = 1) AND ID_PARKOVISKA = " + parkId + " and (X >= " + minX + " and X < " + maxX + ") and (Y >= " + minY + " and Y < " + maxY + ")";
#define SYNC_LOAD_STALLS_FROM_TIME(parkId, minX, maxX, minY, maxY, from) "select * from PR_PARKOVACIE_MIESTO pm join PR_VSTUP v on pm.ID_PARKOVISKA = v.ID_PARKOVISKA where pm.ID_PARK_MIESTA = v.ID_PARK_MIESTA and v.ZACIATOK <= to_date('" + from + "','DD.MM.YY HH24:MI:SS') and (v.KONIEC >= to_date('" + from + "','DD.MM.YY HH24:MI:SS') or v.KONIEC is null) and pm.ID_PARKOVISKA = " + parkId + " and (pm.X >= " + minX + " and pm.X < " + maxX + ") and (pm.Y >= " + minY + " and pm.Y < " + maxY + ")";
#define SYNC_LOAD_PARKS_DATA "select * from SYNC_VERZIE_P_MIESTA"
#define LOAD_CURRENT_PARK(parkId) "select * from SYNC_VERZIE_P_MIESTA where ID_PARKOVISKA = " + parkId