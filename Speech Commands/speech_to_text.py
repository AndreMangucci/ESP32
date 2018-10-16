import speech_recognition as sr

r = sr.Recognizer()
with sr.Microphone() as source:
    r.adjust_for_ambient_noise(source)
    while 1 :
        print("Speak Anything :")
        audio = r.listen(source,timeout=10.0)
        try:
            text = r.recognize_google(audio)
            print("You said : {}".format(text))
        except:
            print("Sorry could not recognize what you said")