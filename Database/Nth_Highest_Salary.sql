/*
 * Nth_Highest_Salary.sql
 * Copyright (C) 2015 fuel <fuel@fuel-7420>
 *
 * Distributed under terms of the MIT license.
 */
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set N = N-1;
  RETURN (
    SELECT DISTINCT Salary -- ?
    FROM Employee 
    ORDER BY Salary DESC
    LIMIT N,1
  );
END
