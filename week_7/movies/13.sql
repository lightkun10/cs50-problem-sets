-- inspired by yama from Discord Chat

-- how can I take all movie staring Kevin Bacon then exclude him?

SELECT people.name
FROM people
JOIN stars ON stars.person_id = people.id
JOIN (
    SELECT *
    FROM movies
    JOIN stars ON stars.movie_id = movies.id
    JOIN people ON people.id = stars.person_id
    WHERE people.name = "Kevin Bacon" AND people.birth = 1958
) AS kbmovies ON kbmovies.id = stars.movie_id
WHERE people.name != "Kevin Bacon";

-- SELECT name
-- FROM people
-- JOIN stars ON stars.person_id = people.id
-- JOIN movies ON stars.movie_id = movies.id
-- WHERE people.name = "Kevin Bacon" AND people.birth = 1958;