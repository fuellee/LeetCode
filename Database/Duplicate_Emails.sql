/*
 * Duplicate_Emails.sql
 * Copyright (C) 2015 fuel <fuel@fuel-7420>
 *
 * Distributed under terms of the MIT license.
 */

SELECT Email
FROM Person
GROUP BY Email
HAVING count(*) > 1;
