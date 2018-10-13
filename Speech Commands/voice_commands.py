import speech_recognition as sr

import socket

target_host = "192.168.15.26"
target_port = 80
from time import sleep

while 1:
    # create a socket object
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # connect the client
    client.connect((target_host, target_port))

    data = ''

    while data == '' :
        r = sr.Recognizer()
        with sr.Microphone() as source:
            print("Speak Anything :")
            audio = r.listen(source)
            try:
                data = r.recognize_google(audio)
                print("You said : {}".format(data))
            except:
                pass

    if data == "exit":
        break
    # send some data
    data = data + "!"
    client.sendall((data).encode())
