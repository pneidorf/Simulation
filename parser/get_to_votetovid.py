import requests

import time







 
    
def functionC():
    filename = "1000x1000_point.txt"
    filewname = "st0_en100000_point.txt"
    url_get = "https://votetovid.ru/hgt/"
    headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/41.0.2228.0 Safari/537.36',}
    start = 0
    end = 100000
    i = start
    file_w = open(filewname, "a")
    file_r = open(filename, "r")
    dDd = 30
    step = 0
    while(i <= end):
        s = file_r.readline()
        s = s[:-1]
        if(i >= start):
            url1 = url_get + s + "/"
            r1 = requests.get(url1, headers=headers)
            
            if(step >= dDd):
                print("[PAUSE] - ", i)
                step = 0
                time.sleep(3)
            


            if(1):
                
                    
                    s_content = r1.content
                    
                    s_content = s_content.decode('ascii')
                    if(len(s_content) < 10):
                        #s_content = "|"
                        print("[",i,"]", s_content)
                        s_w = s + " " + s_content + "\n"
                        file_w.write(s_w)
                        i += 1
                    else:
                        print("No write: ")
                    step += 1
            else:
                    print("status = ", r1.status_code)
                    print("Error: ", i)
                    file_w.write("error: end - "+ str(i) + "\n")
                    file_w.write(url1 + "\n")
                    con_write = False
                    time.sleep(2)
            time.sleep(0.002)        
    
    file_w.write(str(end) + "\n")    
    file_w.close()
    file_r.close()    


functionC()



