import requests
import re
import time
import urllib
import random

ua = ["Mozilla/5.0 (Windows; U; Windows NT 6.1; en-us) AppleWebKit/534.50 (KHTML, like Gecko) Version/5.1",
      "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/49.0.2623.221 Safari/537.36 SE 2.X MetaSr 1.0",
      "Mozilla/5.0 (Windows NT 10.0; WOW64; rv:52.0) Gecko/20100101 Firefox/52.0",
      'Mozilla/5.0 (Windows NT 6.2; rv:16.0) Gecko/20100101 Firefox/16.0',
      'Mozilla/5.0 (Windows; U; Windows NT 6.0; en-US) AppleWebKit/534.16 (KHTML, like Gecko) Chrome/10.0.648.133 Safari/534.16',
      'Mozilla/5.0 (Windows; U; Windows NT 6.0; en-US) AppleWebKit/534.13 (KHTML, like Gecko) Chrome/9.0.597.0 Safari/534.13',
      'Mozilla/5.0 (Windows; U; Windows NT 6.0; en-US) AppleWebKit/533.3 (KHTML, like Gecko) Chrome/8.0.552.224 Safari/533.3',
      'Mozilla/5.0 (Windows; U; Windows NT 6.0; en-US) AppleWebKit/534.8 (KHTML, like Gecko) Chrome/7.0.521.0 Safari/534.8',
      'Mozilla/5.0 (Windows; U; Windows NT 6.0; en-US) AppleWebKit/534.3 (KHTML, like Gecko) Chrome/6.0.458.1 Safari/534.3',
      'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/536.3 (KHTML, like Gecko) Chrome/19.0.1061.1 Safari/536.3',
      'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/536.3 (KHTML, like Gecko) Chrome/19.0.1061.1 Safari/536.3',
      'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.66 Safari/535.11',
      'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.66 Safari/535.11',
      'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11',
      'Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/535.8 (KHTML, like Gecko) Chrome/17.0.940.0 Safari/535.8',
      'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/535.7 (KHTML, like Gecko) Chrome/16.0.912.77 Safari/535.7ad-imcjapan-syosyaman-xkgi3lqg03!wgz'
      ]
def parse_html(url):
    '''
    :param url:  请求的网址
    :return: 解析出的结果页面
    '''
    req = urllib.request.Request(url)
    req.add_header('User-Agent',random.choice(ua))
    req.add_header('allow_redirect', False)
    # open = urllib.build_opener()
    html_source = urllib.request.urlopen(req).read()
    return str(html_source, 'utf-8')

# url = "http://www.ziroom.com/z/vr/60205224.html"
url = 'http://m.ziroom.com/BJ/room?id=60205224'
header={ 'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_5) AppleWebKit/537.36 (KHTML, like Gecko)'}
print ("starting")
session = requests.session()
while 1:
    try:
        # html = requests.get(url,headers=header)
        # string = html.headers['Location']
        string = parse_html(url)
        # response_ziroom = session.get(url,headers=header)
        webpage_result = re.compile(r'title="配置中"')
        # analyze_result = re.search(webpage_result, response_ziroom._content)
        analyze_result = re.search(webpage_result, string)
        print(string)
        print(analyze_result)
        if analyze_result:
            print("still processing! wait!")
            print(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))
            time.sleep(30)
        else:
            # get163mail(5)
            print(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))
            print("quick get it!")
            break
    except Exception as e:
        print(e)
        print("fuck socket is closed, retry...")
        time.sleep(120)
        continue