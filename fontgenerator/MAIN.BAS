' dos-day 2015 demo by
' @messagemaetens and signalwerk
' 2015 - MIT License

' the path to the font files
CONST Path$ = "C:\Eigene~1\Dosday15\txt\"

' define the COM-Parameters
' OPEN "COMn: Speed, Parity, Bits, Stopbit, [Options]" [FOR mode] AS #P [LEN = bytesize]
CONST comPort$ = "com1:"                         'let us hope it is COM1 ...
CONST comMode$ = "9600,n,8,1"      'Use 0 to avoid timeouts

' declare the subs
DECLARE SUB printFile (filename$)
DECLARE SUB printString (toPrint$)

' setup the screen
CLS

' open connection
OPEN "com1:9600,n,8,1" FOR OUTPUT AS 1

LOCATE 3, 12
COLOR 15
PRINT "Herzlich Willkommen beim DOS-Tag 2015"
PRINT " "
PRINT " "

DO
  printstr$ = ""
  WHILE IN$ <> "": WEND
  PRINT "Bitte Buchstaben zum drucken eingeben:"
  DO
    IN$ = INKEY$
    SELECT CASE IN$
    CASE CHR$(32) TO CHR$(122)
        printstr$ = printstr$ + IN$
        PRINT IN$;
    CASE ELSE
        
    END SELECT
  LOOP UNTIL IN$ = CHR$(13) OR IN$ = CHR$(27)
  IF LEN(printstr$) > 0 THEN printString (printstr$)


LOOP UNTIL LEN(printstr$) = 0
REM Abschneiden
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
    'PRINT char
    printFile (Path$ + LTRIM$(STR$(charNr)) + ".txt")

  NEXT LETTER
 
END SUB

