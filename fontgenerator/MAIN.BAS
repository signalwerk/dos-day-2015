' dos-day 2015 demo by
' @messagemaetens and signalwerk
' 2015 - MIT License

DIM SHARED p

' the path to the font files
CONST Path$ = "C:\Eigene~1\Dosday15\txt\"

' define the COM-Parameters
' OPEN "COMn: Speed, Parity, Bits, Stopbit, [Options]" [FOR mode] AS #P [LEN = bytesize]
CONST comMode$ = "9600,N,8,1"      'Use 0 to avoid timeouts

' declare the subs
DECLARE SUB printFile (filename$)
DECLARE SUB printString (toPrint$)

' setup the screen
SCREEN 12
CLS


' open connection
p = FREEFILE
comPort$ = "COM1:"                         'let us hope it is COM1 ...
    OPEN comPort$ + comModes$ FOR OUTPUT AS p

LOCATE 3, 12
COLOR 15
PRINT "Herzlich Willkommen beim DOS-Tag 2015"
PRINT " "
PRINT " "

DO

  INPUT "Bitte Buchstaben zum drucken eingeben:", printstr$
  'PRINT printstr$
  IF LEN(printstr$) > 0 THEN printString (printstr$)


LOOP UNTIL LEN(printstr$) = 0
SYSTEM

SUB printFile (filename$)

  ' open file
  f = FREEFILE
  'PRINT filename$
  OPEN filename$ FOR INPUT AS f

  IF 1 THEN
    PRINT #p, "??"
    CLOSE f
  ELSE
    DO WHILE NOT EOF(f)
       'PRINT f
       LINE INPUT #f, dataline$
       PRINT dataline$
       PRINT #p, dataline$
    LOOP
    PLAY "l4 o3 ceg o4c"
  END IF

  CLOSE f


END SUB

' takes a string and calls for each letter the printFile()
SUB printString (toPrint$)
SHARED p

  FOR LETTER = 1 TO LEN(toPrint$)

    char$ = MID$(toPrint$, LETTER, 1)
    charNr = ASC(char$)
    'PRINT char
    printFile (Path$ + LTRIM$(STR$(charNr)) + ".txt")

  NEXT LETTER
 
END SUB

