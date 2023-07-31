from bs4 import BeautifulSoup as bs
import requests
import time
import pandas as pd

start_time = time.time()

pages = []
vals = []
dictKey = ['name', 'price', 'percent change', 'open', 'high', 'low', 'volume']


def scrape():
    for page_num in range(1, 139):
        url = 'https://www.centralcharts.com/en/price-list-ranking/ALL/asc/ts_19-us-nasdaq-stocks--qc_1-alphabetical-order?p=' + str(
            page_num)
        html_text = requests.get(url)
        soup = bs(html_text.text, 'html.parser')

        table = soup.find('table', class_='tabMini tabQuotes')
        tr_tags = table.find_all('tr')

        for tr_tag in tr_tags[1:]:
            td_tags = tr_tag.find_all('td')

            row_dict = {}
            valRefIdx = 0
            for td_tag in td_tags[0:7]:
                val = td_tag.text.strip()
                row_dict[dictKey[valRefIdx]] = val
                valRefIdx += 1

            vals.append(row_dict)


stockDF = pd.DataFrame.from_records(vals)
print(stockDF)
print('Total time: ' + str(time.time() - start_time) + 's')
