/*
 * Department_Top_Three_Salaries.sql
 * Copyright (C) 2015 fuel <fuel@fuel-7420>
 *
 * Distributed under terms of the MIT license.
 */

select
    Department,
    Employee,
    Salary
from (
    select 
        D.Name as Department,
        E.Name as Employee,
        Salary,
        ROW_NUMBER() OVER (PARTITION BY DepartmentId ORDER BY Salary DESC) AS ROW_NUMBER
    from Employee E, Department D
    where E.DepartmentId=D.Id
)
where ROW_NUMBER <=3;

-- MySQL 居然不支持 ROW_NUMBER, 渣渣
Select
    dep.Name as Department,
    emp.Name as Employee,
    emp.Salary from Department dep, 
    Employee emp
where
    emp.DepartmentId=dep.Id and 
    (Select count(distinct Salary) From Employee where DepartmentId=dep.Id and Salary>emp.Salary)<3
