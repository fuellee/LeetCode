-- solution one (in)
select 
    t.Request_at Day, 
    round(sum(if(t.Status in ('cancelled_by_client','cancelled_by_driver'),1,0))/count(*), 2) Rate
from
    Trips t, Users u 
where t.Client_Id = u.Users_Id and u.Banned='No' and t.Request_at between '2013-10-01' and '2013-10-03'
group by t.Request_at

-- solution two (like)
select 
    t.Request_at Day, 
    round(sum(if(t.Status like 'cancelled_%',1,0))/count(*), 2) Rate
from
    Trips t, Users u 
where t.Client_Id = u.Users_Id and u.Banned='No' and t.Request_at between '2013-10-01' and '2013-10-03'
group by t.Request_at
