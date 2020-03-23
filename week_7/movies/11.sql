-- write a SQL query to list the titles of the 
-- five highest rated movies (in order) that Chadwick Boseman 
-- starred in, starting with the highest rated.

SELECT movies.title
FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON stars.movie_id = movies.id
JOIN ratings ON ratings.movie_id = movies.id
WHERE people.name = "Chadwick Boseman"
ORDER BY ratings.rating DESC
LIMIT 5;