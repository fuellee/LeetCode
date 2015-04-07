/*
 * Consecutive_Numbers.sql
 * Copyright (C) 2015 fuel <fuel@fuel-7420>
 *
 * Distributed under terms of the MIT license.
 */

SELECT DISTINCT T2.Num
FROM Logs as T1, Logs as T2, Logs as T3
WHERE T1.Id+1 = T2.Id
  and T2.Id = T3.Id-1
  and T1.Num = T2.Num
  and T2.Num = T3.Num;
