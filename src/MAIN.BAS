' DOS-Day 2015 demo by
' Stephan Gubler and signalwerk
' 2015 - MIT License

' the path to the font files
CONST Path$ = "C:\Eigene~1\Dosday15\txt\"

' declare the subs
DECLARE SUB printFile (filename$)
DECLARE SUB printString (toPrint$)

' setup the screen
CLS

' open connection to printer
' OPEN "COMn: Speed, Parity, Bits, Stopbit, [Options]" [FOR mode] AS #P [LEN = bytesize]
OPEN "com1:9600,n,8,1" FOR OUTPUT AS 1

LOCATE 3, 12
COLOR 15
PRINT "Say hi to DOS-Day 2015!"
PRINT " "
PRINT " "

DO
  INPUT "Please enter your text for print:", printstr$
  IF LEN(printstr$) > 0 THEN printString (printstr$)
LOOP UNTIL LEN(printstr$) = 0

' cut paper and close connection to printer
PRINT #1, CHR$(&H1D) + "VB" + CHR$(10)
CLOSE 1
SYSTEM

SUB printFile (filename$)

  ' open file
  f = FREEFILE
  OPEN filename$ FOR INPUT AS f

  DO WHILE NOT EOF(f)
    LINE INPUT #f, dataline$
    PRINT dataline$
    PRINT #1, dataline$
  LOOP

  CLOSE f
END SUB

' takes a string and calls for each letter the printFile()
SUB printString (toPrint$)

  FOR LETTER = 1 TO LEN(toPrint$)
    char$ = MID$(toPrint$, LETTER, 1)
    charNr = ASC(char$)
    printFile (Path$ + LTRIM$(STR$(charNr)) + ".txt")
  NEXT LETTER 
END SUB
