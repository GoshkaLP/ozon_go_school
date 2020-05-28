SELECT goods_id, (SELECT name FROM goods WHERE id = goods_id)
FROM tags_goods tg
WHERE (SELECT COUNT(id) FROM tags) = (SELECT COUNT(tag_id) FROM tags_goods WHERE goods_id = tg.goods_id)
GROUP BY goods_id