import urllib
import re
import os

if(not(os.path.exists('/home/buddy/tmp/'))):
    os.makedirs('/home/buddy/tmp/')

def get_content(url):
    html = urllib.urlopen(url)
    content = html.read()
    html.close()
    
    return content

def get_images(info):
    """doc.
    <img class="BDE_Image" src="http://imgsrc.baidu.com/forum/w%3D580/sign=47e1b51ea56eddc426e7b4f309dab6a2/d6023af33a87e9507c3f689718385343fbf2b427.jpg" size="9266" width="421" height="750">
    """
    regex = r'class="BDE_Image" src="(.+?\.jpg)"'
    pat = re.compile(regex)
    images_code = re.findall(pat,info)

    i = 0
    for image_url in images_code:
        print image_url
        urllib.urlretrieve(image_url,'/home/buddy/tmp/%s.jpg'%i)
        i += 1

url = raw_input('pls input your url:')
info = get_content(url)
get_images(info)

