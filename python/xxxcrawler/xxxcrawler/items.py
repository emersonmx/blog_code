# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class XXXCrawlerItem(scrapy.Item):
    image = scrapy.Field()
    title = scrapy.Field()
    url = scrapy.Field()
    time = scrapy.Field()
    rated = scrapy.Field()
