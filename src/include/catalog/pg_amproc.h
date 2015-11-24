/*-------------------------------------------------------------------------
 *
 * pg_amproc.h
 *	  definition of the system "amproc" relation (pg_amproc)
 *	  along with the relation's initial contents.
 *
 * The amproc table identifies support procedures associated with index
 * operator families and classes.  These procedures can't be listed in pg_amop
 * since they are not the implementation of any indexable operator.
 *
 * The primary key for this table is <amprocfamily, amproclefttype,
 * amprocrighttype, amprocnum>.  The "default" support functions for a
 * particular opclass within the family are those with amproclefttype =
 * amprocrighttype = opclass's opcintype.  These are the ones loaded into the
 * relcache for an index and typically used for internal index operations.
 * Other support functions are typically used to handle cross-type indexable
 * operators with oprleft/oprright matching the entry's amproclefttype and
 * amprocrighttype. The exact behavior depends on the index AM, however, and
 * some don't pay attention to non-default functions at all.
 *
 *
 * Portions Copyright (c) 1996-2008, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $PostgreSQL: pgsql/src/include/catalog/pg_amproc.h,v 1.61 2006/12/23 00:43:12 tgl Exp $
 *
 * NOTES
 *	  the genbki.sh script reads this file and generates .bki
 *	  information from the DATA() statements.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_AMPROC_H
#define PG_AMPROC_H

#include "catalog/genbki.h"

/* TIDYCAT_BEGINFAKEDEF

   CREATE TABLE pg_amproc
   with (camelcase=AccessMethodProcedure, oid=false, relid=2603)
   (
   amprocfamily   oid,
   amproclefttype oid,
   amprocrighttype oid,
   amprocnum      smallint, 
   amproc         regproc
   );

   create unique index on pg_amproc(amprocfamily, amproclefttype, amprocrighttype, amprocnum) with (indexid=2655, CamelCase=AccessMethodProcedure, syscacheid=AMPROCNUM, syscache_nbuckets=64);

   alter table pg_amproc add fk amprocfamily on pg_opfamily(oid);
   alter table pg_amproc add fk amproclefttype on pg_type(oid);
   alter table pg_amproc add fk amprocrighttype on pg_type(oid);
   alter table pg_amproc add fk amproc on pg_proc(oid);

   TIDYCAT_ENDFAKEDEF
*/

/* ----------------
 *		pg_amproc definition.  cpp turns this into
 *		typedef struct FormData_pg_amproc
 * ----------------
 */
#define AccessMethodProcedureRelationId  2603

CATALOG(pg_amproc,2603)
{
	Oid			amprocfamily;		/* the index opfamily this entry is for */
	Oid			amproclefttype;		/* procedure's left input data type */
	Oid			amprocrighttype;	/* procedure's right input data type */
	int2		amprocnum;			/* support procedure index */
	regproc		amproc;				/* OID of the proc */
} FormData_pg_amproc;

/* ----------------
 *		Form_pg_amproc corresponds to a pointer to a tuple with
 *		the format of pg_amproc relation.
 * ----------------
 */
typedef FormData_pg_amproc *Form_pg_amproc;

/* ----------------
 *		compiler constants for pg_amproc
 * ----------------
 */
#define Natts_pg_amproc					5
#define Anum_pg_amproc_amprocfamily		1
#define Anum_pg_amproc_amproclefttype	2
#define Anum_pg_amproc_amprocrighttype	3
#define Anum_pg_amproc_amprocnum		4
#define Anum_pg_amproc_amproc			5

/* ----------------
 *		initial contents of pg_amproc
 * ----------------
 */

/* btree */
DATA(insert (	397   2277 2277 1 382 ));
DATA(insert (	421   702 702 1 357 ));
DATA(insert (	423   1560 1560 1 1596 ));
DATA(insert (	424   16 16 1 1693 ));
DATA(insert (	426   1042 1042 1 1078 ));
DATA(insert (	428   17 17 1 1954 ));
DATA(insert (	429   18 18 1 358 ));
DATA(insert (	434   1082 1082 1 1092 ));
DATA(insert (	434   1082 1114 1 2344 ));
DATA(insert (	434   1082 1184 1 2357 ));
DATA(insert (	434   1114 1114 1 2045 ));
DATA(insert (	434   1114 1082 1 2370 ));
DATA(insert (	434   1114 1184 1 2526 ));
DATA(insert (	434   1184 1184 1 1314 ));
DATA(insert (	434   1184 1082 1 2383 ));
DATA(insert (	434   1184 1114 1 2533 ));
DATA(insert (	1970   700 700 1 354 ));
DATA(insert (	1970   700 701 1 2194 ));
DATA(insert (	1970   701 701 1 355 ));
DATA(insert (	1970   701 700 1 2195 ));
DATA(insert (	1974   869 869 1 926 ));
DATA(insert (	1976   21 21 1 350 ));
DATA(insert (	1976   21 23 1 2190 ));
DATA(insert (	1976   21 20 1 2192 ));
DATA(insert (	1976   23 23 1 351 ));
DATA(insert (	1976   23 20 1 2188 ));
DATA(insert (	1976   23 21 1 2191 ));
DATA(insert (	1976   20 20 1 842 ));
DATA(insert (	1976   20 23 1 2189 ));
DATA(insert (	1976   20 21 1 2193 ));
DATA(insert (	1982   1186 1186 1 1315 ));
DATA(insert (	1984   829 829 1 836 ));
DATA(insert (	1986   19 19 1 359 ));
DATA(insert (	1988   1700 1700 1 1769 ));
DATA(insert (	1989   26 26 1 356 ));
DATA(insert (	1991   30 30 1 404 ));
DATA(insert (	1994   25 25 1 360 ));
DATA(insert (	1996   1083 1083 1 1107 ));
DATA(insert (	2000   1266 1266 1 1358 ));
DATA(insert (	2002   1562 1562 1 1672 ));
DATA(insert (	2095   25 25 1 2166 ));
DATA(insert (	2097   1042 1042 1 2180 ));
DATA(insert (	2098   19 19 1 2187 ));
DATA(insert (	2099   790 790 1  377 ));
DATA(insert (	2233   703 703 1  380 ));
DATA(insert (	2234   704 704 1  381 ));
DATA(insert (	2789   27 27 1 2794 ));
DATA(insert (	7080   3310 3310 1 7081 ));


/* hash */
DATA(insert (	427   1042 1042 1 1080 ));
DATA(insert (	431   18 18 1 454 ));
DATA(insert (	435   1082 1082 1 450 ));
DATA(insert (	1971   700 700 1 451 ));
DATA(insert (	1971   701 701 1 452 ));
DATA(insert (	1975   869 869 1 422 ));
DATA(insert (	1977   21 21 1 449 ));
DATA(insert (	1977   23 23 1 450 ));
DATA(insert (	1977   20 20 1 949 ));
DATA(insert (	1983   1186 1186 1 1697 ));
DATA(insert (	1985   829 829 1 399 ));
DATA(insert (	1987   19 19 1 455 ));
DATA(insert (	1990   26 26 1 453 ));
DATA(insert (	1992   30 30 1 457 ));
DATA(insert (	1995   25 25 1 400 ));
DATA(insert (	1997   1083 1083 1 452 ));
DATA(insert (	1998   1700 1700 1 432 ));
DATA(insert (	1999   1184 1184 1 452 ));
DATA(insert (	2001   1266 1266 1 1696 ));
DATA(insert (	2040   1114 1114 1 452 ));
DATA(insert (	2222   16 16 1 454 ));
DATA(insert (	2223   17 17 1 456 ));
DATA(insert (	2224   22 22 1 398 ));
DATA(insert (	2225   28 28 1 450 ));
DATA(insert (	2226   29 29 1 450 ));
DATA(insert (	2227   702 702 1 450 ));
DATA(insert (	2228   703 703 1 450 ));
DATA(insert (	2229   25 25 1 456 ));
DATA(insert (	2231   1042 1042 1 456 ));
DATA(insert (	2232   19 19 1 455 ));
DATA(insert (	2235   1033 1033 1 329 ));


/* gist */
DATA(insert (	2593   603 603 1 2578 ));
DATA(insert (	2593   603 603 2 2583 ));
DATA(insert (	2593   603 603 3 2579 ));
DATA(insert (	2593   603 603 4 2580 ));
DATA(insert (	2593   603 603 5 2581 ));
DATA(insert (	2593   603 603 6 2582 ));
DATA(insert (	2593   603 603 7 2584 ));
DATA(insert (	2594   604 604 1 2585 ));
DATA(insert (	2594   604 604 2 2583 ));
DATA(insert (	2594   604 604 3 2586 ));
DATA(insert (	2594   604 604 4 2580 ));
DATA(insert (	2594   604 604 5 2581 ));
DATA(insert (	2594   604 604 6 2582 ));
DATA(insert (	2594   604 604 7 2584 ));
DATA(insert (	2595   718 718 1 2591 ));
DATA(insert (	2595   718 718 2 2583 ));
DATA(insert (	2595   718 718 3 2592 ));
DATA(insert (	2595   718 718 4 2580 ));
DATA(insert (	2595   718 718 5 2581 ));
DATA(insert (	2595   718 718 6 2582 ));
DATA(insert (	2595   718 718 7 2584 ));

/* gin */
DATA(insert (	2745   1007 1007 1  351 ));
DATA(insert (	2745   1007 1007 2 2743 ));
DATA(insert (	2745   1007 1007 3 2743 ));
DATA(insert (	2745   1007 1007 4 2744 ));
DATA(insert (	2745   1009 1009 1  360 ));
DATA(insert (	2745   1009 1009 2 2743 ));
DATA(insert (	2745   1009 1009 3 2743 ));
DATA(insert (	2745   1009 1009 4 2744 ));
DATA(insert (	2745   1023 1023 1 357 ));
DATA(insert (	2745   1023 1023 2 2743 ));
DATA(insert (	2745   1023 1023 3 2743 ));
DATA(insert (	2745   1023 1023 4 2744 ));
DATA(insert (	2745   1561 1561 1 1596 ));
DATA(insert (	2745   1561 1561 2 2743 ));
DATA(insert (	2745   1561 1561 3 2743 ));
DATA(insert (	2745   1561 1561 4 2744 ));
DATA(insert (	2745   1000 1000 1 1693 ));
DATA(insert (	2745   1000 1000 2 2743 ));
DATA(insert (	2745   1000 1000 3 2743 ));
DATA(insert (	2745   1000 1000 4 2744 ));
DATA(insert (	2745   1014 1014 1 1078 ));
DATA(insert (	2745   1014 1014 2 2743 ));
DATA(insert (	2745   1014 1014 3 2743 ));
DATA(insert (	2745   1014 1014 4 2744 ));
DATA(insert (	2745   1001 1001 1 1954 ));
DATA(insert (	2745   1001 1001 2 2743 ));
DATA(insert (	2745   1001 1001 3 2743 ));
DATA(insert (	2745   1001 1001 4 2744 ));
DATA(insert (	2745   1002 1002 1 358 ));
DATA(insert (	2745   1002 1002 2 2743 ));
DATA(insert (	2745   1002 1002 3 2743 ));
DATA(insert (	2745   1002 1002 4 2744 ));
DATA(insert (	2745   1182 1182 1 1092 ));
DATA(insert (	2745   1182 1182 2 2743 ));
DATA(insert (	2745   1182 1182 3 2743 ));
DATA(insert (	2745   1182 1182 4 2744 ));
DATA(insert (	2745   1021 1021 1 354 ));
DATA(insert (	2745   1021 1021 2 2743 ));
DATA(insert (	2745   1021 1021 3 2743 ));
DATA(insert (	2745   1021 1021 4 2744 ));
DATA(insert (	2745   1022 1022 1 355 ));
DATA(insert (	2745   1022 1022 2 2743 ));
DATA(insert (	2745   1022 1022 3 2743 ));
DATA(insert (	2745   1022 1022 4 2744 ));
DATA(insert (	2745   1041 1041 1 926 ));
DATA(insert (	2745   1041 1041 2 2743 ));
DATA(insert (	2745   1041 1041 3 2743 ));
DATA(insert (	2745   1041 1041 4 2744 ));
DATA(insert (	2745   1005 1005 1 350 ));
DATA(insert (	2745   1005 1005 2 2743 ));
DATA(insert (	2745   1005 1005 3 2743 ));
DATA(insert (	2745   1005 1005 4 2744 ));
DATA(insert (	2745   1016 1016 1 842 ));
DATA(insert (	2745   1016 1016 2 2743 ));
DATA(insert (	2745   1016 1016 3 2743 ));
DATA(insert (	2745   1016 1016 4 2744 ));
DATA(insert (	2745   1187 1187 1 1315 ));
DATA(insert (	2745   1187 1187 2 2743 ));
DATA(insert (	2745   1187 1187 3 2743 ));
DATA(insert (	2745   1187 1187 4 2744 ));
DATA(insert (	2745   1040 1040 1 836 ));
DATA(insert (	2745   1040 1040 2 2743 ));
DATA(insert (	2745   1040 1040 3 2743 ));
DATA(insert (	2745   1040 1040 4 2744 ));
DATA(insert (	2745   1003 1003 1 359 ));
DATA(insert (	2745   1003 1003 2 2743 ));
DATA(insert (	2745   1003 1003 3 2743 ));
DATA(insert (	2745   1003 1003 4 2744 ));
DATA(insert (	2745   1231 1231 1 1769 ));
DATA(insert (	2745   1231 1231 2 2743 ));
DATA(insert (	2745   1231 1231 3 2743 ));
DATA(insert (	2745   1231 1231 4 2744 ));
DATA(insert (	2745   1028 1028 1 356 ));
DATA(insert (	2745   1028 1028 2 2743 ));
DATA(insert (	2745   1028 1028 3 2743 ));
DATA(insert (	2745   1028 1028 4 2744 ));
DATA(insert (	2745   1013 1013 1 404 ));
DATA(insert (	2745   1013 1013 2 2743 ));
DATA(insert (	2745   1013 1013 3 2743 ));
DATA(insert (	2745   1013 1013 4 2744 ));
DATA(insert (	2745   1183 1183 1 1107 ));
DATA(insert (	2745   1183 1183 2 2743 ));
DATA(insert (	2745   1183 1183 3 2743 ));
DATA(insert (	2745   1183 1183 4 2744 ));
DATA(insert (	2745   1185 1185 1 1314 ));
DATA(insert (	2745   1185 1185 2 2743 ));
DATA(insert (	2745   1185 1185 3 2743 ));
DATA(insert (	2745   1185 1185 4 2744 ));
DATA(insert (	2745   1270 1270 1 1358 ));
DATA(insert (	2745   1270 1270 2 2743 ));
DATA(insert (	2745   1270 1270 3 2743 ));
DATA(insert (	2745   1270 1270 4 2744 ));
DATA(insert (	2745   1563 1563 1 1672 ));
DATA(insert (	2745   1563 1563 2 2743 ));
DATA(insert (	2745   1563 1563 3 2743 ));
DATA(insert (	2745   1563 1563 4 2744 ));
DATA(insert (	2745   1115 1115 1 2045 ));
DATA(insert (	2745   1115 1115 2 2743 ));
DATA(insert (	2745   1115 1115 3 2743 ));
DATA(insert (	2745   1115 1115 4 2744 ));
DATA(insert (	2745   791 791 1 377 ));
DATA(insert (	2745   791 791 2 2743 ));
DATA(insert (	2745   791 791 3 2743 ));
DATA(insert (	2745   791 791 4 2744 ));
DATA(insert (	2745   1024 1024 1 380 ));
DATA(insert (	2745   1024 1024 2 2743 ));
DATA(insert (	2745   1024 1024 3 2743 ));
DATA(insert (	2745   1024 1024 4 2744 ));
DATA(insert (	2745   1025 1025 1 381 ));
DATA(insert (	2745   1025 1025 2 2743 ));
DATA(insert (	2745   1025 1025 3 2743 ));
DATA(insert (	2745   1025 1025 4 2744 ));

/*
 * the operator routines for the on-disk bitmap index.
 */
DATA(insert (	3014	702 702 1 357 ));		/* abstime */
DATA(insert (	3015	2277  2277 1 382 ));		/* array */
DATA(insert (	3016	1560  1560 1 1596 ));	/* bit */
DATA(insert (	3017	16  16 1 1693 ));	/* bool */
DATA(insert (	3018	1042  1042 1 1078 ));	/* bpchar */
DATA(insert (	3019	17  17 1 1954 ));	/* bytea */
DATA(insert (	3020	 18   18 1 358 ));		/* char */
DATA(insert (	3022	1082  1082 1 1092 ));	/* date */
DATA(insert (	3022 1082 1114 1 2344 ));	/* date-timestamp */
DATA(insert (	3022 1082 1184 1 2357 ));	/* date-timestamptz */
DATA(insert (	3023	700  700 1 354 ));		/* float4 */
DATA(insert (	3023  700 701 1 2194 ));	/* float48 */
DATA(insert (	3024	701  701 1 355 ));		/* float8 */
DATA(insert (	3024  701 700 1 2195 ));	/* float84 */
DATA(insert (	3025	869  869 1  926 ));	/* inet */
DATA(insert (	3026	 21   21 1 350 ));		/* int2 */
DATA(insert (	3026   21 23 1 2190 ));	/* int24 */
DATA(insert (	3026   21 20 1 2192 ));	/* int28 */
DATA(insert (	3027	 23   23 1 351 ));		/* int4 */
DATA(insert (	3027   23 20 1 2191 ));	/* int42 */
DATA(insert (	3027   23 21 1 2188 ));	/* int48 */
DATA(insert (	3028	 20   20 1 842 ));		/* int8 */
DATA(insert (	3028   20 21 1 2193 ));	/* int82 */
DATA(insert (	3028   20 23 1 2189 ));	/* int84 */
DATA(insert (	3029	1186  1186 1 1315 ));	/* interval */
DATA(insert (	3030	 829   829 1  836 ));	/* macaddr */
DATA(insert (	3031	 19   19 1 359 ));		/* name */
DATA(insert (	3032	1700  1700 1 1769 ));	/* numeric */
DATA(insert (	3033	 26   26 1 356 ));		/* oid */
DATA(insert (	3034	 30   30 1 404 ));		/* oidvector */
DATA(insert (	3035	 25   25 1 360 ));		/* text */
DATA(insert (	3036	1083  1083 1 1107 ));	/* time */
DATA(insert (	3037	1184  1184 1 1314 ));	/* timestamptz */
DATA(insert (	3037 1184 1082 1 2383 ));	/* timestamptz-date */
DATA(insert (	3037 1184 1114 1 2533 ));	/* timestamptz-timestamp */
DATA(insert (	3038	1266  1266 1 1358 ));	/* timetz */
DATA(insert (	3039	1562  1562 1 1672 ));	/* varbit */
DATA(insert (	3041	1114  1114 1 2045 ));	/* timestamp */
DATA(insert (	3041 1114 1082 1 2370 ));	/* timestamp-date */
DATA(insert (	3041 1114 1184 1 2526 ));	/* timestamp-timestamptz */
DATA(insert (	3042	 25   25 1 2166 ));	/* text pattern */
DATA(insert (	3044	1042  1042 1 2180 ));	/* bpchar pattern */
DATA(insert (	3045	 19   19 1 2187 ));	/* name pattern */
DATA(insert (	3046	790  790 1  377 ));	/* money */
DATA(insert (	3047	703  703 1 380 ));		/* reltime */
DATA(insert (	3048	704  704 1 381 ));		/* tinterval */


#endif   /* PG_AMPROC_H */
