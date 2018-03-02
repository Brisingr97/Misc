import os
from twilio.rest import Client
import datetime as dt
import time
start_time_of_application = time.time()
account_sid = os.environ["TWILIO_ACCOUNT_SID"] #change it to your credentials
from_number = os.environ["TWILIO_FROM_NUMBER"]
auth_token  = os.environ["TWILIO_AUTH_TOKEN"]   # ----------------------------
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
    time_now = dt.datetime.today().hour
    while(time_now<22 and time_now>6):
        # however this method is buggy as it's the time of the server and not john, I couldn't find the API link to extract
        # information about john's time zones.
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
