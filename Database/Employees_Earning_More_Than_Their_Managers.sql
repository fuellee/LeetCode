/*
 * Employees_Earning_More_Than_Their_Managers.sql
 * Copyright (C) 2015 fuel <fuel@fuel-7420>
 *
 * Distributed under terms of the MIT license.
 */

SELECT E1.Name
FROM Employee AS E1 INNER JOIN Employee AS E2 -- Inner join will not expand NULL
ON E1.ManagerId=E2.Id
WHERE E1.Salary>E2.Salary;
