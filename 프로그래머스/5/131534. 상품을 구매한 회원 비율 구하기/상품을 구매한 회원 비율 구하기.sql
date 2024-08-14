-- 코드를 입력하세요
SELECT 
    EXTRACT(YEAR FROM S.SALES_DATE) AS YEAR,
    EXTRACT(MONTH FROM S.SALES_DATE) AS MONTH,
    COUNT(DISTINCT S.USER_ID) AS PURCHASED_USERS,
    ROUND(COUNT(DISTINCT S.USER_ID) / (SELECT 
                                    COUNT(*)
                                 FROM
                                    USER_INFO
                                 WHERE
                                    EXTRACT(YEAR FROM JOINED) = '2021'), 1) AS PURCHASED_RATIO
                                    
FROM 
    ONLINE_SALE S
INNER JOIN 
    USER_INFO I
ON 
    S.USER_ID = I.USER_ID
WHERE
    EXTRACT(YEAR FROM I.JOINED) = '2021'
GROUP BY 
    EXTRACT(YEAR FROM S.SALES_DATE),
    EXTRACT(MONTH FROM S.SALES_DATE)
ORDER BY
    YEAR ASC,
    MONTH ASC;