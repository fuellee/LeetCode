/*
 * Customers_Who_Never_Order.sql
 * Copyright (C) 2015 fuel <fuel@fuel-7420>
 *
 * Distributed under terms of the MIT license.
 */
-- BEST: `NOT IN`
SELECT Name
FROM Customers
where Customers.Id NOT IN
      (SELECT CustomerId FROM Orders);

-- NOT EXISTS / NOT IN
SELECT Name
FROM Customers
where NOT EXISTS
      (SELECT 1 FROM Orders where Customers.Id = Orders.CustomerId);

-- LEFT JOIN & filter by NULL
SELECT Name
FROM Customers LEFT JOIN Orders
     ON Customers.Id = Orders.CustomerId
where CustomerId IS NULL;
