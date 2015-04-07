/*
 * Rising_Temperature.sql
 * Copyright (C) 2015 fuel <fuel@fuel-7420>
 *
 * Distributed under terms of the MIT license.
 */

SELECT D1.Id
FROM Weather as D1 , Weather as D2
WHERE DATE_SUB(D1.Date, INTERVAL 1 day) = D2.Date 
  and D1.Temperature > D2.Temperature;

SELECT D1.Id 
FROM Weather as D1 , Weather as D2
WHERE TO_DAYS(D1.DATE)-TO_DAYS(D2.DATE)=1 
  and D1.Temperature > D2.Temperature;
