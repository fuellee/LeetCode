/*
 * Combine_Two_Tables.sql
 * Copyright (C) 2015 fuel <fuel@fuel-7420>
 *
 * Distributed under terms of the MIT license.
 */

SELECT FirstName, LastName, City, State
FROM Person LEFT JOIN Address
ON Person.PersonId = Address.PersonId;
