' dos-day 2015 demo by
' @messagemaetens and signalwerk
' 2015 - MIT License

DIM Path AS STRING      'root path to the font files


' the path to the font files
CONST Path$ = "A:\font\txt\"

' define the COM-Parameters
' OPEN "COMn: Speed, Parity, Bits, Stopbit, [Options]" [FOR mode] AS #P [LEN = bytesize]
CONST comMode$ = "9600,N,8,1,CS0,DS0"      'Use 0 to avoid timeouts 



' declare the subs
DECLARE SUB printFile (filename$)
DECLARE SUB printString (toPrint$)

' setup the screen
SCREEN 12
CLS


' open connection
p = FREEFILE
comPort$ = "COM1:"                         'let us hope it is COM1 ...
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
SUB printString (toPrint$)

  FOR LETTER = 1 TO LEN(toPrint$)

    char$ = MID$(toPrint$,LETTER,1)
    charNr = ASC(char$)

    printFile (  Path$ + charNr$ + ".txt" )

  NEXT LETTER
 
END SUB




LOCATE 3, 12
COLOR 15
PRINT "Herzlich Willkommen beim DOS-Tag 2015"
PRINT " "
PRINT " "

DO

  INPUT "Bitte Buchstaben zum drucken eingeben:", printstr$
  PRINT printstr$
  IF LEN(printstr$) > 0 THEN printString(printstr$)


LOOP UNTIL LEN(printstr$) = 0
SYSTEM