/*
 * Delete_Duplicate_Emails.sql
 * Copyright (C) 2015 fuel <fuel@fuel-7420>
 *
 * Distributed under terms of the MIT license.
 */

delete P from Person P, Person Q where P.Id>Q.Id and Q.Email=P.Email 
