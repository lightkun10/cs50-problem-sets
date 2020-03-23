-- write a SQL query to list the names of all 
-- people who have directed a movie that 
-- received a rating of at least 9.0.

SELECT name
FROM people
JOIN directors
ON directors.person_id = people.id
JOIN movies
ON movies.id = directors.movie_id
JOIN ratings
ON movies.id = ratings.movie_id
WHERE ratings.rating >= 9.0
GROUP BY people.id;