#include <stdint.h>
#include <Arduino.h>

namespace AVE55{

const String MIX_MODE = "VMX:000";
const String WIPE_SQUARE = "VWP:017";

}

/*  
Mode Slide-Compression	VWM	053	 	Wipe Mode	 	 	 	 	 
Operation Over	VWM	054	 	Wipe Operation	 	 	 	 	 
Operation Remove	VWM	055	 	Wipe Operation	 	 	 	 	 
Operation Flip	VWM	056	 	Wipe Operation	 	 	 	 	 
Operation Push	VWM	057	 	Wipe Operation	 	 	 	 	 
 	???	058	 	 	 	 	 	 	 
 	???	059	 	 	 	 	 	 	 
 	???	060	 	 	 	 	 	 	 
SpEdge None	VWB	061	 	Special Edge	 	 	 	 	 
SpEdge Border	VWB	062	 	Special Edge	 	 	 	 	 
SpEdge Soft	VWB	063	 	Special Edge	 	 	 	 	 
 	???	064	 	 	 	 	 	 	 
 	???	065	 	 	 	 	 	 	 
 	???	066	 	 	 	 	 	 	 
 	???	067	 	 	 	 	 	 	 
 	???	068	 	 	 	 	 	 	 
 	???	069	 	 	 	 	 	 	 
a-bus strobo off	VDE	070	 	Video digital effect	 	 	 	 	 
a-bus strobo step 1	VDE	071	 	Video digital effect	 	 	 	 	 
a-bus strobo step 2	VDE	072	 	Video digital effect	 	 	 	 	 
a-bus strobo step 3	VDE	073	 	Video digital effect	 	 	 	 	 
a-bus strobo step 4	VDE	074	 	Video digital effect	 	 	 	 	 
a-bus strobo step 5	VDE	075	 	Video digital effect	 	 	 	 	 
a-bus mosaic off	VDE	076	 	Video digital effect	 	 	 	 	 
a-bus mosaic step 1	VDE	077	 	Video digital effect	 	 	 	 	 
a-bus mosaic step 2	VDE	078	 	Video digital effect	 	 	 	 	 
a-bus mosaic step 3	VDE	079	 	Video digital effect	 	 	 	 	 
a-bus mosaic step 4	VDE	080	 	Video digital effect 	 	 	 	 	 
a-bus mosaic step 5	VDE	081	 	Video digital effect 	 	 	 	 	 
a-bus paint off	VDE	082	 	Video digital effect 	 	 	 	 	 
a-bus paint step 1	VDE	083	 	Video digital effect 	 	 	 	 	 
a-bus paint step 2	VDE	084	 	Video digital effect 	 	 	 	 	 
a-bus paint step 3	VDE	085	 	Video digital effect 	 	 	 	 	 
a-bus paint step 4	VDE	086	 	Video digital effect 	 	 	 	 	 
a-bus negative off	VDE	087	 	Video digital effect 	 	 	 	 	 
a-bus negative on	VDE	088	 	Video digital effect 	 	 	 	 	 
a-bus field still mode	VDE	089	 	Video digital effect 	 	 	 	 	 
a-bus frame still mode	VDE	090	 	Video digital effect 	 	 	 	 	 
a-bus color corrector off	VDE	091	 	Video digital effect 	 	 	 	 	 
a-bus color corrector on	VDE	092	 	Video digital effect 	 	 	 	 	 
a-bus chroma level	VDE	093	xx	Video digital effect 	xx =(ASCII HEX 01H-17H)	 	 	 	 
b-bus strobo off	VDE	094	 	Video digital effect	 	 	 	 	 
b-bus strobo step 1	VDE	095	 	Video digital effect	 	 	 	 	 
b-bus strobo step 2	VDE	096	 	Video digital effect	 	 	 	 	 
b-bus strobo step 3	VDE	097	 	Video digital effect	 	 	 	 	 
b-bus strobo step 4	VDE	098	 	Video digital effect	 	 	 	 	 
b-bus strobo step 5	VDE	099	 	Video digital effect	 	 	 	 	 
b-bus mosaic off	VDE	100	 	Video digital effect	 	 	 	 	 
b-bus mosaic step 1	VDE	101	 	Video digital effect	 	 	 	 	 
b-bus mosaic step 2	VDE	102	 	Video digital effect	 	 	 	 	 
b-bus mosaic step 3	VDE	103	 	Video digital effect	 	 	 	 	 
b-bus mosaic step 4	VDE	104	 	Video digital effect 	 	 	 	 	 
b-bus mosaic step 5	VDE	105	 	Video digital effect 	 	 	 	 	 
b-bus paint off	VDE	106	 	Video digital effect 	 	 	 	 	 
b-bus paint step 1	VDE	107	 	Video digital effect 	 	 	 	 	 
b-bus paint step 2	VDE	108	 	Video digital effect 	 	 	 	 	 
b-bus paint step 3	VDE	109	 	Video digital effect 	 	 	 	 	 
b-bus paint step 4	VDE	110	 	Video digital effect 	 	 	 	 	 
b-bus negative off	VDE	111	 	Video digital effect 	 	 	 	 	 
b-bus negative on	VDE	112	 	Video digital effect 	 	 	 	 	 
b-bus field still mode	VDE	113	 	Video digital effect 	 	 	 	 	 
b-bus frame still mode	VDE	114	 	Video digital effect 	 	 	 	 	 
b-bus color corrector off	VDE	115	 	Video digital effect 	 	 	 	 	 
b-bus color corrector on	VDE	116	 	Video digital effect 	 	 	 	 	 
b-bus chroma level	VDE	117	xx	Video digital effect 	xx =(ASCII HEX 01H-17H)	 	 	 	 
 	???	118	 	 	 	 	 	 	 
 	???	119	 	 	 	 	 	 	 
Audio Mix Level global follow on
AML	120	 	Audio	 	 	 	 	 
Audio Mix Level global follow off
AML	121	 	Audio	 	 	 	 	 
Audio Level source 1	ALV	122	xx	Audio	(xx is ASCII 00H-1AH)	 	 	 	 
Audio Level source 2	ALV	123	xx	Audio	(xx is ASCII 00H-1AH)	 	 	 	 
Audio Level source 3	ALV	124	xx	Audio	(xx is ASCII 00H-1AH)	 	 	 	 
Audio Level source 4	ALV	125	xx	Audio	(xx is ASCII 00H-1AH)	 	 	 	 
Audio Mix Level source 4 follow on
AML	126	 	Audio	 	 	 	 	 
Audio Mix Level source 4 follow off
AML	127	 	Audio	 	 	 	 	 
 	???	128	 	 	 	 	 	 	 
 	???	129	 	 	 	 	 	 	 
Video fade on	VFD	130	 	Fade	 	 	 	 	 
Video fade off	VFD	131	 	Fade	 	 	 	 	 
Audio fade on	VFD	132	 	Fade	 	 	 	 	 
Audio fade off	VFD	133	 	Fade	 	 	 	 	 
Tittle fade on	VFD	134	 	Fade	 	 	 	 	 
Tittle fade off	VFD	135	 	Fade	 	 	 	 	 
Fade to White	VFD	136	 	Fade	 	 	 	 	 
Fade to Black	VFD	137	 	Fade	 	 	 	 	 
Fade to Color	VFD	138	 	Fade	 	 	 	 	 
 	???	139	 	 	 	 	 	 	 
Back Color - white	VBC	140	 	Set background color	 	 	 	 	 
Back Color - yellow	VBC	141	 	Set background color	 	 	 	 	 
Back Color - cyan	VBC	142	 	Set background color	 	 	 	 	 
Back Color - green	VBC	143	 	Set background color	 	 	 	 	 
Back Color - magenta	VBC	144	 	Set background color	 	 	 	 	 
Back Color - red	VBC	145	 	Set background color	 	 	 	 	 
Back Color - blue	VBC	146	 	Set background color	 	 	 	 	 
Back Color - black	VBC	147	 	Set background color	 	 	 	 	 
Back Color - User color	VBC	148	 	Set background color	set by 174	 	 	 	 
 	???	149	 	 	 	 	 	 	 
Edge Color - white	VEC	150	 	Set edge color	 	 	 	 	 
Edge Color - yellow	VEC	151	 	Set edge color	 	 	 	 	 
Edge Color - cyan	VEC	152	 	Set edge color	 	 	 	 	 
Edge Color - green	VEC	153	 	Set edge color	 	 	 	 	 
Edge Color - magenta	VEC	154	 	Set edge color	 	 	 	 	 
Edge Color - red	VEC	155	 	Set edge color	 	 	 	 	 
Edge Color - blue	VEC	156	 	Set edge color	 	 	 	 	 
Edge Color - black	VEC	157	 	Set edge color	 	 	 	 	 
Edge Color - User color	VEC	158	 	Set edge color	set by 175	 	 	 	 
 	???	159	 	 	 	 	 	 	 
Color Mode normal	VBG	160	 	Color Mode	 	 	 	 	 
Color Mode vertical	VBG	161	 	Color Mode	 	 	 	 	 
Color Mode horizontal	VBG	162	 	Color Mode	 	 	 	 	 
Color Mode lines	VBG	163	 	Color Mode	 	 	 	 	 
Color Mode palette	VBG	164	 	Color Mode	 	 	 	 	 
title Color internal (back color)
VTC	165	 	Title colr	internal color - using back color	 	 	 	 
title Color external	VTC	166	 	Title color	external color - controlled by titler	 	 	 	 
Title edge pattern 0 off	VTE	167	 	Tittle pattern	 	 	 	 	 
Title edge pattern 1	VTE	168	 	Tittle pattern	 	 	 	 	 
Title edge pattern 2	VTE	169	 	Tittle pattern	 	 	 	 	 
Title edge pattern 3	VTE	170	 	Tittle pattern	 	 	 	 	 
Title edge pattern 4	VTE	171	 	Tittle pattern	 	 	 	 	 
Title edge pattern 5	VTE	172	 	Tittle pattern	 	 	 	 	 
 	???	173	 	 	 	 	 	 	 
Back Color - Manual	VBM	174	xxyy	Set user color: 	
xx = B-Y (ASCII HEX 00H-FFH)
yy = R-Y (ASCII HEX 00H-FFH)
 	 	 	 
Edge Color - Manual	VEM	175	xxyy	Set user color: 	
xx = B-Y (ASCII HEX 00H-FFH)
yy = R-Y (ASCII HEX 00H-FFH)
 	 	 	 
 	???	176	 	 	 	 	 	 	 
 	???	177	 	 	 	 	 	 	 
 	???	178	 	 	 	 	 	 	 
A-B Mix LEVEL	VMM	179	xx	POTENTIOMETRE	00=A, FF=B	 	 	 	 
A-bus EFFECT on	VDE	180	 	BUTTON	 	 	 	 	 
A-bus EFFECT off	VDE	181	 	BUTTON	 	 	 	 	 
B-bus EFFECT on	VDE	182	 	BUTTON	 	 	 	 	 
B-bus EFFECT off	VDE	183	 	BUTTON	 	 	 	 	 
A-bus STILL on	VDE	184	 	BUTTON	 	 	 	 	 
A-bus STILL off	VDE	185	 	BUTTON	 	 	 	 	 
B-bus STILL on	VDE	186	 	BUTTON	 	 	 	 	 
B-bus STILL off	VDE	187	 	BUTTON	 	 	 	 	 
 	???	188	 	 	 	 	 	 
 	???	189	 	 	 	 	 	 	 
Speed set	VAS	190	xx	POTENTIOMETRE	xx =(ASCII HEX 01H-FFH)	 	 	 	 
FADE button	VFM	191	 	BUTTON	 	 	 	 	 
TAKE button	VMA	192	 	BUTTON	 	 	 	 	 
???????????????	ZYC	193	 	??????????	COMP ON ?	 	 	 	 
???????????????	ZYC	194	 	??????????	COMP OFF ?	 	 	 	 
 	???	195	 	 	 	 	 	 	 
 	???	196	 	 	 	 	 	 	 
Back Color - color bars	VBC	197	 	test	 	 	 	 	 
Back Color - Not color bars	VBC	198	 	test	 	 	 	 	 
Reset to factory settings	ZRS	199	 	Reset	 	 	 	 	 
A-bus SOURCE 1	VCP	200	 	BUTTON	 	 	 	 	 
A-bus SOURCE 2	VCP	201	 	BUTTON	 	 	 	 	 
A-bus SOURCE 3	VCP	202	 	BUTTON	 	 	 	 	 
A-bus SOURCE 4	VCP	203	 	BUTTON	 	 	 	 	 
A-bus BACK COLOR	VCP	204	 	BUTTON	 	 	 	 	 
B-bus SOURCE 1	VCP	205	 	BUTTON	 	 	 	 	 
B-bus SOURCE 2	VCP	206	 	BUTTON	 	 	 	 	 
B-bus SOURCE 3	VCP	207	 	BUTTON	 	 	 	 	 
B-bus SOURCE 4	VCP	208	 	BUTTON	 	 	 	 	 
B-bus BACK COLOR	VCP	209	 	BUTTON	 	 	 	 	 
WIPE/MIX Button	VMX	210	 	BUTTON	 	 	 	 	 
Set threshold of luminance key	VMX	211	xx	BUTTON	(xx = ASCII HEX 00H FFH)	 	 	 	 
LUM KEY	VMX	212	 	BUTTON	 	 	 	 	 
Chroma KEY	VMX	213	 	BUTTON	 	 	 	 	 
Chroma SET	VCS	214	xxyyzz	BUTTON	3 couleurs en mémoire ?	 	 	 	 
UNDO	ZUD	215	 	BUTTON	 	 	 	 	 
ENTER	ZEN	216	 	BUTTON	 	 	 	 	 
POSITION: Color Corect	VPS	217	xxyy	POSITION	 	 	 	 	 
POSITION: center wipe / PnP	VPS	218	xxyy	POSITION	(xx = horizontal) (yy - vertical) (ASCII HEX 00H-FFH)	 	 	 	 
POSITION: Scene Graber	VPS	219	xxyy	POSITION	 	 	 	 	 
Event memory select	WGP	220	no	Event memory	no=01...04 clear=00	 	 	 	 
 	???	221	 	 	 	 	 	 	 
Event call	WGP	222	xx	Event memory	Ne marche pas	 	 	 	 
Event call off	WGP	223	xx	Event memory	Ne marche pas	 	 	 	 
 	 	 	 	 	 	 	 	 	 
 	 	 	 	 	 	 	 	 	 
 	 	 	 	 	 	 	 	 	 
Request Lanp Status	QLS	 	 	Returns RAM data in ASCII that has lamp status encoded?	 	 	 	 	 
Request On	RON	 	 	mixer sends a ""#"" in period of V-Sync	 	 	 	 	 
Request Off	ROF	 	 	Request to stop sending ""#""	 	 	 	 	 
ID Request	QID	 	 	Returns av mixer id value	 	 	 	 	 
*/