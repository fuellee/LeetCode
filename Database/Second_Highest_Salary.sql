/*
 * Second_Highest_Salary.sql
 * Copyright (C) 2015 fuel <fuel@fuel-7420>
 *
 * Distributed under terms of the MIT license.
 */

SELECT max(Salary)
FROM Employee
where Salary < (SELECT max(Salary) FROM Employee);
