import os
from twilio.rest import Client
import datetime as dt
import time
start_time_of_application = time.time()
account_sid = "ACa50028be5efc1b4d5c231e47fa77c467" #change it to your credentials
from_number = "+15712817239"
auth_token  = "19d21fb17e2fd4ea56ee95b3918e1a83"   # ----------------------------
client = Client(account_sid, auth_token)
def send_message(client_val,to_num,from_num,body_val):
    message = client_val.messages.create(
        to=to_num, 
        from_=from_num,
        body=body_val)
    query_num = message.sid
    print(query_num)
    return [client_val.messages(query_num).fetch().status,query_num]

failed_messages = []
to_number = input("Enter your ph.number John: ")
while(True):    
    status_val = (send_message(client,to_number,from_number,"Your name is John, John."))   
    counter = 0 
    while(status_val[0]!="delivered"):
        # wait for a second and try again
        counter = counter+1
        if(counter==4):
            print("Not delivered, Tried.")
            failed_messages = failed_messages + [status_val]
            break
        time.sleep(60)
        status_val = (send_message(client,to_number,from_number,"Your name is John, John."))
    time.sleep(3600)
    print(str((time.time()-start_time_of_application)/3600)+" hours have passed since the program began")

