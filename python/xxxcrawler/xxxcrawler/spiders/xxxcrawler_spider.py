#!/usr/bin/env python
# encoding: utf-8

import scrapy

from xxxcrawler.items import XXXCrawlerItem

class XXXCrawlerSpider(scrapy.Spider):

    name = 'XXXCrawler'
    allowed_domains= ['xnxx.com']
    start_urls = ['http://www.xnxx.com/']

    def parse(self, response):
        for thumbs in response.xpath('//div[@class="thumbs"]/ul[@class="ti"]/li/div'): 
            item = XXXCrawlerItem()
            item['image'] = thumbs.xpath('a/img/@src').extract_first()
            item['title']= thumbs.xpath('div[@class="t_all"]/span/text()').extract_first()
            item['url'] = thumbs.xpath('a/@href').extract_first()
            font = thumbs.xpath('div[@class="t_all"]/font/text()')
            matches = font.re('(\d+ \w+) sex rated (\d+\%|\? \%)')
            item['time'] = matches[0]
            item['rated'] = matches[1]
            yield item
