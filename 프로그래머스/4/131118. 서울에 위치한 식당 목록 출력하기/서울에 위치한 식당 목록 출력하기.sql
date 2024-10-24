SELECT REST_INFO.REST_ID, REST_INFO.REST_NAME, REST_INFO.FOOD_TYPE, REST_INFO.FAVORITES, REST_INFO.ADDRESS, 
ROUND(AVG(REVIEW_SCORE), 2) AS SCORE
FROM REST_INFO 
JOIN REST_REVIEW ON REST_INFO.REST_ID = REST_REVIEW.REST_ID
GROUP BY REST_INFO.REST_ID
HAVING REST_INFO.ADDRESS LIKE '서울%' 
ORDER BY SCORE DESC, REST_INFO.FAVORITES DESC