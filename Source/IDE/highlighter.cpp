#include <QtGui>
#include "highlighter.h"

 Highlighter::Highlighter(QTextDocument *parent)
     : QSyntaxHighlighter(parent)
 {
     HighlightingRule rule;

     keywordFormat.setForeground(Qt::darkBlue);
     keywordFormat.setFontWeight(QFont::Bold);
     QStringList keywordPatterns;
     keywordPatterns << "\\bchar\\b" << "\\bclass\\b" << "\\bconst\\b"
                     << "\\bdouble\\b" << "\\benum\\b" << "\\bexplicit\\b"
                     << "\\bfriend\\b" << "\\binline\\b" << "\\bint\\b"
                     << "\\blong\\b" << "\\bnamespace\\b" << "\\boperator\\b"
                     << "\\bprivate\\b" << "\\bprotected\\b" << "\\bpublic\\b"
                     << "\\bshort\\b" << "\\bsignals\\b" << "\\bsigned\\b"
                     << "\\bslots\\b" << "\\bstatic\\b" << "\\bstruct\\b"
                     << "\\btemplate\\b" << "\\btypedef\\b" << "\\btypename\\b"
                     << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
                     << "\\bvoid\\b" << "\\bvolatile\\b";
     foreach (const QString &pattern, keywordPatterns) {
         rule.pattern = QRegExp(pattern);
         rule.format = keywordFormat;
         highlightingRules.append(rule);
     }

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(255, 125, 0));
     rule.pattern = QRegExp("\[A]A");
     rule.format = classFormat;
     highlightingRules.append(rule);
    //****************** EB GB
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(Qt::darkRed);
     rule.pattern = QRegExp("\[B-D]A");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(Qt::darkRed);
     rule.pattern = QRegExp("\[A-D]I");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(Qt::darkRed);
     rule.pattern = QRegExp("\[I]I");
     rule.format = classFormat;
     highlightingRules.append(rule);
    //*****************  EB GB
    //*****************  EV GV
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(Qt::blue);
     rule.pattern = QRegExp("\[A-D]B");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(Qt::blue);
     rule.pattern = QRegExp("\[A-D]J");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(Qt::blue);
     rule.pattern = QRegExp("\[I]J");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  EV GV
     //*****************  GB EB
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(189, 26, 173));
     rule.pattern = QRegExp("\[A-D]C");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(189, 26, 173));
     rule.pattern = QRegExp("\[I]E");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(189, 26, 173));
     rule.pattern = QRegExp("\[I]G");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(189, 26, 173));
     rule.pattern = QRegExp("\[A-D]K");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  GB EB
     //*****************  AL IB
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(Qt::gray);
     rule.pattern = QRegExp("\[A-D]E");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(Qt::gray);
     rule.pattern = QRegExp("\[L]A");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(Qt::gray);
     rule.pattern = QRegExp("\[P]E");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(Qt::gray);
     rule.pattern = QRegExp("\[A-D]M");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(Qt::gray);
     rule.pattern = QRegExp("\[K]A");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  AL IB
     //*****************  AX IV
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(29, 226, 226));
     rule.pattern = QRegExp("\[A-D]F");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(29, 226, 226));
     rule.pattern = QRegExp("\[A-D]N");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(29, 226, 226));
     rule.pattern = QRegExp("\[L]A");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  AX IV
     //*****************  GV EV
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(44, 122, 239));
     rule.pattern = QRegExp("\[A-D]D");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(44, 122, 239));
     rule.pattern = QRegExp("\[I]F");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(44, 122, 239));
     rule.pattern = QRegExp("\[I]H");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(44, 122, 239));
     rule.pattern = QRegExp("\[A-D]L");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(44, 122, 239));
     rule.pattern = QRegExp("\[I]L");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  GV EV
     //*****************  AX
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[E]A");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[F]A");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[E]I");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[F]I");
     rule.format = classFormat;
     highlightingRules.append(rule);
	//*****************  AX
    //*****************  CX 
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[E]B");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[F]B");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[E]J");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[F]J");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  DX 
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[E]C");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[F]C");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[E]K");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[F]K");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  BX
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[E]D");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[F]D");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[E]L");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(27, 47, 222));
     rule.pattern = QRegExp("\[F]L");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  BX
     //*****************  SP
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(28, 191, 185));
     rule.pattern = QRegExp("\[E]E");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(28, 191, 185));
     rule.pattern = QRegExp("\[F]E");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(28, 191, 185));
     rule.pattern = QRegExp("\[E]M");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(28, 191, 185));
     rule.pattern = QRegExp("\[F]M");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  SP
     //*****************  BP
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(28, 191, 185));
     rule.pattern = QRegExp("\[E]F");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(28, 191, 185));
     rule.pattern = QRegExp("\[F]F");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(28, 191, 185));
     rule.pattern = QRegExp("\[E]N");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(28, 191, 185));
     rule.pattern = QRegExp("\[F]N");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  BP
     //*****************  SI
	 classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(111, 174, 174));
     rule.pattern = QRegExp("\[E]G");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(111, 174, 174));
     rule.pattern = QRegExp("\[F]G");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(111, 174, 174));
     rule.pattern = QRegExp("\[E]P");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(111, 174, 174));
     rule.pattern = QRegExp("\[F]P");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  DI
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(111, 174, 174));
     rule.pattern = QRegExp("\[E]H");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(111, 174, 174));
     rule.pattern = QRegExp("\[F]H");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(111, 174, 174));
     rule.pattern = QRegExp("\[E]O");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(111, 174, 174));
     rule.pattern = QRegExp("\[F]O");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  DI
     //*****************  JB
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(165,42,42));
     rule.pattern = QRegExp("\H[A-H]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(165,42,42));
     rule.pattern = QRegExp("\P[A-D]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(165,42,42));
     rule.pattern = QRegExp("\H[I-O]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(165,42,42));
     rule.pattern = QRegExp("\[P]L");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  JB 
     //*****************  AL IB
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(66,178,118));
     rule.pattern = QRegExp("\[A-D]E");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(66,178,118));
     rule.pattern = QRegExp("\[L]A");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(66,178,118));
     rule.pattern = QRegExp("\[P]E");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(66,178,118));
     rule.pattern = QRegExp("\[A-D]M");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(66,178,118));
     rule.pattern = QRegExp("\[K]I");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  AL IB
     //*****************  CL IB
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(66,178,118));
     rule.pattern = QRegExp("\[L]B");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  CL IB
     //*****************  DL IB
	 classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(66,178,118));
     rule.pattern = QRegExp("\[L]D");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  DL IB
     //*****************  AH IB
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(33,131,79));
     rule.pattern = QRegExp("\[L]E");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  AH IB
     //*****************  CH IB
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(33,131,79));
     rule.pattern = QRegExp("\[L]F");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  CH IB
     //*****************  DH IB
	 classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(33,131,79));
     rule.pattern = QRegExp("\[L]G");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  DH IB
     //*****************  BH IB
	 classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(33,131,79));
     rule.pattern = QRegExp("\[L]H");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  BH IB
     //*****************  AX IB
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(153,0,0));
     rule.pattern = QRegExp("\[P]F");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  AX IB
     //*****************  CX IV
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(153,0,0));
     rule.pattern = QRegExp("\[L]G");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  CX IV
     //*****************  DX IV
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(153,0,0));
     rule.pattern = QRegExp("\[L]K");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  DX IV
     //*****************  BX IV
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(153,0,0));
     rule.pattern = QRegExp("\[L]L");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  BX IV
     //*****************  SP
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(134,48,48));
     rule.pattern = QRegExp("\[E-F]E");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(134,48,48));
     rule.pattern = QRegExp("\[E-F]M");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  SP
     //*****************  BP
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(134,48,48));
     rule.pattern = QRegExp("\[E-F]F");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(134,48,48));
     rule.pattern = QRegExp("\[E-F]N");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  BP
     //*****************  ES
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(148,0,211));
     rule.pattern = QRegExp("\A[G-H]");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  ES
     //*****************  CS
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(148,0,211));
     rule.pattern = QRegExp("\A[P]");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  CS
     //*****************  SS
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(148,0,211));
     rule.pattern = QRegExp("\B[G-H]");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  SS
     //*****************  DS
	 classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(148,0,211));
     rule.pattern = QRegExp("\B[P-O]");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  DS
     //*****************  I0
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(187,0,0));
     rule.pattern = QRegExp("\N[E-F]");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  I0
     //***************** Where 1
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(204,153,255));
     rule.pattern = QRegExp("\N[A-B]");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //***************** Where 1
     //***************** Where 3
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(3,84,3));
     rule.pattern = QRegExp("\[M]M");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //***************** Where 3
     singleLineCommentFormat.setForeground(Qt::darkGreen);
     rule.pattern = QRegExp("//[^\n]*");
     rule.format = singleLineCommentFormat;
     highlightingRules.append(rule);
     //*****************  SMTH
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\[A-D]G");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\[A-D]H");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\I[A-D]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\I[H]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\O[I-O]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\P[I-O]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\M[K-L]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\M[N-O]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\K[K-O]");
     rule.format = classFormat;
     highlightingRules.append(rule);
     
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\J[I-O]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\I[M-O]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\D[P-O]");
     rule.format = classFormat;
     highlightingRules.append(rule);
     
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\C[P-O]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\O[O]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\O[C-H]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\P[E-H]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\N[A-D]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\N[H]");
     rule.format = classFormat;
     highlightingRules.append(rule);
     
     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\M[C-F]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\K[A-H]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(255,0,00));
     rule.pattern = QRegExp("\G[A-P]");
     rule.format = classFormat;
     highlightingRules.append(rule);


     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\N[N]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(255,0,0));
     rule.pattern = QRegExp("\A[O]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\[I-O]P");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\[H]P");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\J[A-H]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\K[J]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\L[I-J]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\I[K]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\L[C]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\L[M-N]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\L[O]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(255,0,0));
     rule.pattern = QRegExp("\M[A-B]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\M[G-J]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(255,0,0));
     rule.pattern = QRegExp("\N[G]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\N[I]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\N[J]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\N[K-O]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\P[P]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(6,128,120));
     rule.pattern = QRegExp("\O[A-B]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(255,0,0));
     rule.pattern = QRegExp("\M[I]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(255,0,0));
     rule.pattern = QRegExp("\O[B]");
     rule.format = classFormat;
     highlightingRules.append(rule);

     classFormat.setFontWeight(QFont::Bold);
     classFormat.setForeground(QColor(255,0,0));
     rule.pattern = QRegExp("\M[J]");
     rule.format = classFormat;
     highlightingRules.append(rule);
     //*****************  SMTH

     multiLineCommentFormat.setForeground(Qt::darkGreen);

     quotationFormat.setForeground(Qt::green);
     rule.pattern = QRegExp("\".*\"");
     rule.format = quotationFormat;
     highlightingRules.append(rule);

     functionFormat.setFontItalic(true);
     functionFormat.setForeground(Qt::blue);
     rule.pattern = QRegExp("\\b[A-Za-z0-9_]+(?=\\()");
     rule.format = functionFormat;
     highlightingRules.append(rule);

     commentStartExpression = QRegExp("/\\*");
     commentEndExpression = QRegExp("\\*/");
 }

 void Highlighter::highlightBlock(const QString &text)
 {
     foreach (const HighlightingRule &rule, highlightingRules) {
         QRegExp expression(rule.pattern);
         int index = expression.indexIn(text);
         while (index >= 0) {
             int length = expression.matchedLength();
             setFormat(index, length, rule.format);
             index = expression.indexIn(text, index + length);
         }
     }
     setCurrentBlockState(0);

     int startIndex = 0;
     if (previousBlockState() != 1)
         startIndex = commentStartExpression.indexIn(text);

     while (startIndex >= 0) {
         int endIndex = commentEndExpression.indexIn(text, startIndex);
         int commentLength;
         if (endIndex == -1) {
             setCurrentBlockState(1);
             commentLength = text.length() - startIndex;
         } else {
             commentLength = endIndex - startIndex
                             + commentEndExpression.matchedLength();
         }
         setFormat(startIndex, commentLength, multiLineCommentFormat);
         startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
     }
 }
// do it do it
// wct is the best
