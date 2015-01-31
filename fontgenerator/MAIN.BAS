' dos-day 2015 demo by
' @messagemaetens and signalwerk
' 2015 - MIT License

DIM Path AS STRING      'root path to the font files
Path$ = "A:\font\txt\"

' declare the subs
DECLARE SUB printFile ()
DECLARE SUB printString ()

' setup the screen
SCREEN 12
CLS


p = FREEFILE

' open connection
comPort$ = "COM1:"                         'let us hope it is COM1 ...
CONST comMode$ = "9600,N,8,1,CS0,DS0"      'Use 0 to avoid timeouts 
OPEN comPort$ + comMode$ FOR OUTPUT AS p


' sends a text file to serial port
' OPEN "COMn: Speed, Parity, Bits, Stopbit, [Options]" [FOR mode] AS #P [LEN = bytesize]
SUB printFile (filename)
  SHARED p 

  ' open file
  f = FREEFILE
  OPEN filename$ FOR INPUT AS f


  DO WHILE NOT EOF(f) 
    LINE INPUT f, dataline$ 
    PRINT p, dataline$
  LOOP 

  CLOSE f
 
END SUB


' takes a string and calls for each letter the printFile()
SUB printString (toPrint)
  
  FOR LETTER = 1 TO LEN(toPrint$)

    char = MID$(toPrint$,LETTER,1)
    charNr = ASC(char$)

    printFile (  Path$ + charNr$ + ".txt" )

  NEXT LETTER
 
END SUB



LOCATE 12, 12
COLOR 15
PRINT "Herzlich Willkommen beim DOS-Tag 2015"


DO

  INPUT "Bitte Buchstaben zum drucken eingeben", printstr$
  IF LEN(printstr$) > 0 THEN printString(printstr$)

LOOP UNTIL LEN(printstr$) > 0
SYSTEM
