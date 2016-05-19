#line 1 "src/json/json_parser.rl"
#line 62 "src/json/json_parser.rl"


#include <vector>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "json_parser.h"

#define PB(x) values.push_back(x)

inline static jsonString* json_string(char* from, char* to)
{
  return new jsonString(from, to-from);
}

inline static jsonNumber* json_number(char* from, char* to, char* buf, int maxsz)
{
  const int sz = to-from; 

  if (sz > maxsz) throw "fatal";

  memcpy(buf, from, sz);
  buf[sz] = '\000';
 
  return new jsonNumber(strtod(buf, NULL));
}


#line 33 "src/json/json_parser.cc"
static const char _jsonParser_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	7, 1, 8, 1, 9, 1, 10, 1, 
	11, 1, 12, 1, 13, 1, 14, 1, 
	15, 1, 16, 1, 17, 2, 0, 13, 
	2, 0, 17, 2, 1, 13, 2, 1, 
	17, 2, 2, 13, 2, 2, 17, 2, 
	4, 13, 2, 4, 17, 2, 5, 13, 
	2, 5, 17, 2, 6, 13, 2, 6, 
	17, 2, 8, 13, 2, 8, 17, 2, 
	13, 15, 2, 14, 7, 2, 14, 9, 
	2, 14, 15, 2, 16, 3, 2, 16, 
	7, 2, 16, 11, 2, 16, 12, 2, 
	16, 17, 3, 0, 13, 15, 3, 1, 
	13, 15, 3, 2, 13, 15, 3, 4, 
	13, 15, 3, 5, 13, 15, 3, 6, 
	13, 15, 3, 8, 13, 15
};

static const short _jsonParser_key_offsets[] = {
	0, 0, 17, 18, 19, 21, 22, 26, 
	30, 32, 33, 34, 35, 36, 37, 38, 
	39, 43, 44, 45, 46, 47, 48, 49, 
	50, 51, 53, 54, 55, 56, 57, 58, 
	59, 60, 61, 62, 63, 75, 87, 88, 
	93, 98, 99, 101, 118, 119, 125, 131, 
	142, 143, 144, 146, 158, 159, 161, 162, 
	166, 175, 185, 189, 191, 199, 210, 211, 
	212, 213, 214, 215, 216, 217, 223, 227, 
	228, 229, 230, 231, 232, 233, 234, 240, 
	241, 243, 249, 250, 251, 252, 253, 259, 
	260, 261, 262, 268, 269, 270, 271, 277, 
	278, 280, 298, 316, 317, 323, 329, 346, 
	347, 351, 360, 370, 371, 373, 377, 379, 
	387, 398, 399, 400, 401, 402, 403, 404, 
	405, 411, 415, 416, 417, 418, 419, 420, 
	421, 422, 428, 429, 431, 432, 433, 434, 
	435, 441, 442, 443, 444, 450, 451, 452, 
	453, 459, 460, 462, 466, 470, 477, 485, 
	491, 500, 504, 508, 512, 516, 520, 520
};

static const char _jsonParser_trans_keys[] = {
	32, 34, 39, 43, 45, 47, 48, 73, 
	91, 102, 110, 116, 123, 9, 13, 49, 
	57, 34, 47, 10, 13, 39, 48, 73, 
	49, 57, 43, 45, 48, 57, 48, 57, 
	110, 102, 105, 110, 105, 116, 121, 48, 
	73, 49, 57, 110, 102, 105, 110, 105, 
	116, 121, 47, 10, 13, 97, 108, 115, 
	101, 117, 108, 108, 114, 117, 101, 32, 
	34, 39, 47, 95, 125, 9, 13, 65, 
	90, 97, 122, 32, 34, 39, 47, 95, 
	125, 9, 13, 65, 90, 97, 122, 34, 
	32, 47, 58, 9, 13, 32, 47, 58, 
	9, 13, 47, 10, 13, 32, 34, 39, 
	43, 45, 47, 48, 73, 91, 102, 110, 
	116, 123, 9, 13, 49, 57, 34, 32, 
	44, 47, 125, 9, 13, 32, 44, 47, 
	125, 9, 13, 32, 34, 39, 47, 95, 
	9, 13, 65, 90, 97, 122, 39, 47, 
	10, 13, 32, 47, 58, 95, 9, 13, 
	48, 57, 65, 90, 97, 122, 47, 10, 
	13, 39, 48, 73, 49, 57, 32, 44, 
	46, 47, 69, 101, 125, 9, 13, 32, 
	44, 47, 69, 101, 125, 9, 13, 48, 
	57, 43, 45, 48, 57, 48, 57, 32, 
	44, 47, 125, 9, 13, 48, 57, 32, 
	44, 46, 47, 69, 101, 125, 9, 13, 
	48, 57, 110, 102, 105, 110, 105, 116, 
	121, 32, 44, 47, 125, 9, 13, 48, 
	73, 49, 57, 110, 102, 105, 110, 105, 
	116, 121, 32, 44, 47, 125, 9, 13, 
	47, 10, 13, 32, 44, 47, 125, 9, 
	13, 97, 108, 115, 101, 32, 44, 47, 
	125, 9, 13, 117, 108, 108, 32, 44, 
	47, 125, 9, 13, 114, 117, 101, 32, 
	44, 47, 125, 9, 13, 47, 10, 13, 
	32, 34, 39, 43, 45, 47, 48, 73, 
	91, 93, 102, 110, 116, 123, 9, 13, 
	49, 57, 32, 34, 39, 43, 45, 47, 
	48, 73, 91, 93, 102, 110, 116, 123, 
	9, 13, 49, 57, 34, 32, 44, 47, 
	93, 9, 13, 32, 44, 47, 93, 9, 
	13, 32, 34, 39, 43, 45, 47, 48, 
	73, 91, 102, 110, 116, 123, 9, 13, 
	49, 57, 39, 48, 73, 49, 57, 32, 
	44, 46, 47, 69, 93, 101, 9, 13, 
	32, 44, 47, 69, 93, 101, 9, 13, 
	48, 57, 47, 10, 13, 43, 45, 48, 
	57, 48, 57, 32, 44, 47, 93, 9, 
	13, 48, 57, 32, 44, 46, 47, 69, 
	93, 101, 9, 13, 48, 57, 110, 102, 
	105, 110, 105, 116, 121, 32, 44, 47, 
	93, 9, 13, 48, 73, 49, 57, 110, 
	102, 105, 110, 105, 116, 121, 32, 44, 
	47, 93, 9, 13, 47, 10, 13, 97, 
	108, 115, 101, 32, 44, 47, 93, 9, 
	13, 117, 108, 108, 32, 44, 47, 93, 
	9, 13, 114, 117, 101, 32, 44, 47, 
	93, 9, 13, 47, 10, 13, 32, 47, 
	9, 13, 32, 47, 9, 13, 32, 46, 
	47, 69, 101, 9, 13, 32, 47, 69, 
	101, 9, 13, 48, 57, 32, 47, 9, 
	13, 48, 57, 32, 46, 47, 69, 101, 
	9, 13, 48, 57, 32, 47, 9, 13, 
	32, 47, 9, 13, 32, 47, 9, 13, 
	32, 47, 9, 13, 32, 47, 9, 13, 
	0
};

static const char _jsonParser_single_lengths[] = {
	0, 13, 1, 1, 2, 1, 2, 2, 
	0, 1, 1, 1, 1, 1, 1, 1, 
	2, 1, 1, 1, 1, 1, 1, 1, 
	1, 2, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 6, 6, 1, 3, 
	3, 1, 2, 13, 1, 4, 4, 5, 
	1, 1, 2, 4, 1, 2, 1, 2, 
	7, 6, 2, 0, 4, 7, 1, 1, 
	1, 1, 1, 1, 1, 4, 2, 1, 
	1, 1, 1, 1, 1, 1, 4, 1, 
	2, 4, 1, 1, 1, 1, 4, 1, 
	1, 1, 4, 1, 1, 1, 4, 1, 
	2, 14, 14, 1, 4, 4, 13, 1, 
	2, 7, 6, 1, 2, 2, 0, 4, 
	7, 1, 1, 1, 1, 1, 1, 1, 
	4, 2, 1, 1, 1, 1, 1, 1, 
	1, 4, 1, 2, 1, 1, 1, 1, 
	4, 1, 1, 1, 4, 1, 1, 1, 
	4, 1, 2, 2, 2, 5, 4, 2, 
	5, 2, 2, 2, 2, 2, 0, 0
};

static const char _jsonParser_range_lengths[] = {
	0, 2, 0, 0, 0, 0, 1, 1, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 3, 3, 0, 1, 
	1, 0, 0, 2, 0, 1, 1, 3, 
	0, 0, 0, 4, 0, 0, 0, 1, 
	1, 2, 1, 1, 2, 2, 0, 0, 
	0, 0, 0, 0, 0, 1, 1, 0, 
	0, 0, 0, 0, 0, 0, 1, 0, 
	0, 1, 0, 0, 0, 0, 1, 0, 
	0, 0, 1, 0, 0, 0, 1, 0, 
	0, 2, 2, 0, 1, 1, 2, 0, 
	1, 1, 2, 0, 0, 1, 1, 2, 
	2, 0, 0, 0, 0, 0, 0, 0, 
	1, 1, 0, 0, 0, 0, 0, 0, 
	0, 1, 0, 0, 0, 0, 0, 0, 
	1, 0, 0, 0, 1, 0, 0, 0, 
	1, 0, 0, 1, 1, 1, 2, 2, 
	2, 1, 1, 1, 1, 1, 0, 0
};

static const short _jsonParser_index_offsets[] = {
	0, 0, 16, 18, 20, 23, 25, 29, 
	33, 35, 37, 39, 41, 43, 45, 47, 
	49, 53, 55, 57, 59, 61, 63, 65, 
	67, 69, 72, 74, 76, 78, 80, 82, 
	84, 86, 88, 90, 92, 102, 112, 114, 
	119, 124, 126, 129, 145, 147, 153, 159, 
	168, 170, 172, 175, 184, 186, 189, 191, 
	195, 204, 213, 217, 219, 226, 236, 238, 
	240, 242, 244, 246, 248, 250, 256, 260, 
	262, 264, 266, 268, 270, 272, 274, 280, 
	282, 285, 291, 293, 295, 297, 299, 305, 
	307, 309, 311, 317, 319, 321, 323, 329, 
	331, 334, 351, 368, 370, 376, 382, 398, 
	400, 404, 413, 422, 424, 427, 431, 433, 
	440, 450, 452, 454, 456, 458, 460, 462, 
	464, 470, 474, 476, 478, 480, 482, 484, 
	486, 488, 494, 496, 499, 501, 503, 505, 
	507, 513, 515, 517, 519, 525, 527, 529, 
	531, 537, 539, 542, 546, 550, 557, 564, 
	569, 577, 581, 585, 589, 593, 597, 598
};

static const unsigned char _jsonParser_trans_targs_wi[] = {
	1, 2, 5, 6, 16, 24, 149, 9, 
	148, 26, 30, 33, 148, 1, 152, 0, 
	147, 2, 4, 0, 148, 148, 4, 147, 
	5, 149, 9, 152, 0, 8, 8, 151, 
	0, 151, 0, 10, 0, 11, 0, 12, 
	0, 13, 0, 14, 0, 15, 0, 153, 
	0, 149, 17, 152, 0, 18, 0, 19, 
	0, 20, 0, 21, 0, 22, 0, 23, 
	0, 154, 0, 25, 0, 1, 1, 25, 
	27, 0, 28, 0, 29, 0, 155, 0, 
	31, 0, 32, 0, 156, 0, 34, 0, 
	35, 0, 157, 0, 37, 38, 48, 95, 
	51, 158, 37, 51, 51, 0, 37, 38, 
	48, 95, 51, 158, 37, 51, 51, 0, 
	39, 38, 40, 41, 43, 40, 0, 40, 
	41, 43, 40, 0, 42, 0, 40, 40, 
	42, 43, 44, 54, 55, 70, 79, 56, 
	62, 81, 82, 87, 91, 81, 43, 61, 
	0, 45, 44, 46, 47, 52, 158, 46, 
	0, 46, 47, 52, 158, 46, 0, 47, 
	38, 48, 49, 51, 47, 51, 51, 0, 
	39, 48, 50, 0, 47, 47, 50, 40, 
	41, 43, 51, 40, 51, 51, 51, 0, 
	53, 0, 46, 46, 53, 45, 54, 56, 
	62, 61, 0, 46, 47, 57, 52, 58, 
	58, 158, 46, 0, 46, 47, 52, 58, 
	58, 158, 46, 57, 0, 59, 59, 60, 
	0, 60, 0, 46, 47, 52, 158, 46, 
	60, 0, 46, 47, 57, 52, 58, 58, 
	158, 46, 61, 0, 63, 0, 64, 0, 
	65, 0, 66, 0, 67, 0, 68, 0, 
	69, 0, 46, 47, 52, 158, 46, 0, 
	56, 71, 61, 0, 72, 0, 73, 0, 
	74, 0, 75, 0, 76, 0, 77, 0, 
	78, 0, 46, 47, 52, 158, 46, 0, 
	80, 0, 43, 43, 80, 46, 47, 52, 
	158, 46, 0, 83, 0, 84, 0, 85, 
	0, 86, 0, 46, 47, 52, 158, 46, 
	0, 88, 0, 89, 0, 90, 0, 46, 
	47, 52, 158, 46, 0, 92, 0, 93, 
	0, 94, 0, 46, 47, 52, 158, 46, 
	0, 96, 0, 37, 37, 96, 98, 99, 
	103, 104, 121, 145, 105, 113, 101, 159, 
	132, 137, 141, 101, 98, 112, 0, 98, 
	99, 103, 104, 121, 145, 105, 113, 101, 
	159, 132, 137, 141, 101, 98, 112, 0, 
	100, 99, 101, 102, 107, 159, 101, 0, 
	101, 102, 107, 159, 101, 0, 102, 99, 
	103, 104, 121, 130, 105, 113, 101, 132, 
	137, 141, 101, 102, 112, 0, 100, 103, 
	105, 113, 112, 0, 101, 102, 106, 107, 
	109, 159, 109, 101, 0, 101, 102, 107, 
	109, 159, 109, 101, 106, 0, 108, 0, 
	101, 101, 108, 110, 110, 111, 0, 111, 
	0, 101, 102, 107, 159, 101, 111, 0, 
	101, 102, 106, 107, 109, 159, 109, 101, 
	112, 0, 114, 0, 115, 0, 116, 0, 
	117, 0, 118, 0, 119, 0, 120, 0, 
	101, 102, 107, 159, 101, 0, 105, 122, 
	112, 0, 123, 0, 124, 0, 125, 0, 
	126, 0, 127, 0, 128, 0, 129, 0, 
	101, 102, 107, 159, 101, 0, 131, 0, 
	102, 102, 131, 133, 0, 134, 0, 135, 
	0, 136, 0, 101, 102, 107, 159, 101, 
	0, 138, 0, 139, 0, 140, 0, 101, 
	102, 107, 159, 101, 0, 142, 0, 143, 
	0, 144, 0, 101, 102, 107, 159, 101, 
	0, 146, 0, 98, 98, 146, 148, 3, 
	148, 0, 148, 3, 148, 0, 148, 150, 
	3, 7, 7, 148, 0, 148, 3, 7, 
	7, 148, 150, 0, 148, 3, 148, 151, 
	0, 148, 150, 3, 7, 7, 148, 152, 
	0, 148, 3, 148, 0, 148, 3, 148, 
	0, 148, 3, 148, 0, 148, 3, 148, 
	0, 148, 3, 148, 0, 0, 0, 0
};

static const unsigned char _jsonParser_trans_actions_wi[] = {
	0, 15, 15, 7, 7, 0, 7, 0, 
	25, 0, 0, 0, 23, 0, 7, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 29, 82, 82, 29, 
	85, 88, 29, 85, 85, 0, 0, 15, 
	15, 0, 19, 31, 0, 19, 19, 0, 
	0, 0, 17, 17, 17, 17, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 15, 15, 7, 7, 0, 7, 
	0, 25, 0, 0, 0, 23, 0, 7, 
	0, 0, 0, 73, 73, 73, 130, 73, 
	0, 0, 0, 0, 31, 0, 0, 0, 
	15, 15, 0, 19, 0, 19, 19, 0, 
	0, 0, 0, 0, 0, 0, 0, 21, 
	21, 21, 0, 21, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 55, 55, 0, 55, 0, 
	0, 118, 55, 0, 55, 55, 55, 0, 
	0, 118, 55, 0, 0, 0, 0, 0, 
	0, 0, 0, 55, 55, 55, 118, 55, 
	0, 0, 55, 55, 0, 55, 0, 0, 
	118, 55, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 61, 61, 61, 122, 61, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 67, 67, 67, 126, 67, 0, 
	0, 0, 0, 0, 0, 27, 27, 27, 
	79, 27, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 49, 49, 49, 114, 49, 
	0, 0, 0, 0, 0, 0, 0, 37, 
	37, 37, 106, 37, 0, 0, 0, 0, 
	0, 0, 0, 43, 43, 43, 110, 43, 
	0, 0, 0, 0, 0, 0, 33, 94, 
	94, 91, 91, 33, 91, 33, 100, 103, 
	33, 33, 33, 97, 33, 91, 0, 0, 
	15, 15, 7, 7, 0, 7, 0, 25, 
	35, 0, 0, 0, 23, 0, 7, 0, 
	0, 0, 17, 17, 17, 76, 17, 0, 
	0, 0, 0, 35, 0, 0, 0, 15, 
	15, 7, 7, 0, 7, 0, 25, 0, 
	0, 0, 23, 0, 7, 0, 0, 0, 
	0, 0, 0, 0, 9, 9, 0, 9, 
	0, 58, 0, 9, 0, 9, 9, 9, 
	0, 58, 0, 9, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 9, 9, 9, 58, 9, 0, 0, 
	9, 9, 0, 9, 0, 58, 0, 9, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	11, 11, 11, 64, 11, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	13, 13, 13, 70, 13, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 5, 5, 5, 52, 5, 
	0, 0, 0, 0, 0, 0, 0, 1, 
	1, 1, 40, 1, 0, 0, 0, 0, 
	0, 0, 0, 3, 3, 3, 46, 3, 
	0, 0, 0, 0, 0, 0, 17, 17, 
	17, 0, 0, 0, 0, 0, 9, 0, 
	9, 0, 0, 9, 0, 9, 9, 0, 
	0, 9, 0, 0, 9, 9, 9, 0, 
	0, 9, 0, 9, 0, 0, 9, 0, 
	0, 11, 11, 11, 0, 13, 13, 13, 
	0, 5, 5, 5, 0, 1, 1, 1, 
	0, 3, 3, 3, 0, 0, 0, 0
};

static const int jsonParser_start = 1;
static const int jsonParser_first_final = 147;
static const int jsonParser_error = 0;

static const int jsonParser_en_main = 1;
static const int jsonParser_en_hash = 36;
static const int jsonParser_en_array = 97;

#line 91 "src/json/json_parser.rl"

jsonValue* jsonParser::parse(char* content, int size)
{
  int cs;
  int top;
  int stack[20];
  char numbuf[61];
  const int numbufsz = 60;

  char *ps = content;
  char *p = ps;
  char *pe = content + size;

  // user defined
  char* tstart = NULL; 
  std::vector<jsonValue*> values; 
  std::vector<int> array_i;

  
#line 399 "src/json/json_parser.cc"
	{
	cs = jsonParser_start;
	top = 0;
	}
#line 110 "src/json/json_parser.rl"
  
#line 406 "src/json/json_parser.cc"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _out;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _jsonParser_trans_keys + _jsonParser_key_offsets[cs];
	_trans = _jsonParser_index_offsets[cs];

	_klen = _jsonParser_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _jsonParser_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	cs = _jsonParser_trans_targs_wi[_trans];

	if ( _jsonParser_trans_actions_wi[_trans] == 0 )
		goto _again;

	_acts = _jsonParser_actions + _jsonParser_trans_actions_wi[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 4 "src/json/json_parser.rl"
	{ PB(new jsonNull()); }
	break;
	case 1:
#line 6 "src/json/json_parser.rl"
	{ PB(new jsonTrue()); }
	break;
	case 2:
#line 8 "src/json/json_parser.rl"
	{ PB(new jsonFalse()); }
	break;
	case 3:
#line 11 "src/json/json_parser.rl"
	{ tstart=p; }
	break;
	case 4:
#line 11 "src/json/json_parser.rl"
	{
    PB(json_number(tstart, p, numbuf, numbufsz));
  }
	break;
	case 5:
#line 15 "src/json/json_parser.rl"
	{ PB(new jsonNumber(INFINITY)); }
	break;
	case 6:
#line 17 "src/json/json_parser.rl"
	{ PB(new jsonNumber(-INFINITY)); }
	break;
	case 7:
#line 19 "src/json/json_parser.rl"
	{ tstart=p; }
	break;
	case 8:
#line 19 "src/json/json_parser.rl"
	{
    PB(json_string(tstart+1, p-1));
  }
	break;
	case 9:
#line 23 "src/json/json_parser.rl"
	{ tstart=p; }
	break;
	case 10:
#line 23 "src/json/json_parser.rl"
	{
    PB(json_string(tstart, p));
  }
	break;
	case 11:
#line 31 "src/json/json_parser.rl"
	{ {stack[top++] = cs; cs = 36; goto _again;} }
	break;
	case 12:
#line 32 "src/json/json_parser.rl"
	{ {stack[top++] = cs; cs = 97; goto _again;} }
	break;
	case 13:
#line 37 "src/json/json_parser.rl"
	{ 
    if (values.size() < 3) throw "invalid format";
    jsonValue* v = values.back();
    values.pop_back();
    jsonString* k = (jsonString*) values.back(); 
    values.pop_back();
    jsonHash* h = (jsonHash*) values.back();
    h->set(k, v);
  }
	break;
	case 14:
#line 49 "src/json/json_parser.rl"
	{ PB(new jsonHash());}
	break;
	case 15:
#line 49 "src/json/json_parser.rl"
	{ {cs = stack[--top]; goto _again;} }
	break;
	case 16:
#line 53 "src/json/json_parser.rl"
	{ array_i.push_back(values.size()); }
	break;
	case 17:
#line 53 "src/json/json_parser.rl"
	{ 
    jsonArray* a = new jsonArray();
    for (int i=array_i.back(); i<values.size(); i++) a->push(values[i]);
    while (values.size() > array_i.back()) values.pop_back();
    PB(a);
    array_i.pop_back();
    {cs = stack[--top]; goto _again;}
  }
	break;
#line 572 "src/json/json_parser.cc"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_out: {}
	}
#line 111 "src/json/json_parser.rl"

  if (p != pe)
  {
    int err_pos = (int)(p-ps);
    std::cout << "error at: " << err_pos << std::endl;
    throw "error occured while parsing";
  }

  if (values.size() != 1)
  {
    throw "error occured while parsing";
  }

  return values[0];
}

#include <fcntl.h>
#include <unistd.h>

jsonValue* jsonParser::parse_file(const char* filename)
{
  int fh;
  void *mem;
  int size;
  jsonValue* res;

  fh = open(filename, O_RDONLY);
  if (fh < 0)
  {
    throw "cannot open file";
  }

  size = lseek(fh, 0, SEEK_END);
  if (size < 0)
  {
    throw "error";
  }
  lseek(fh, 0, SEEK_SET);

  mem = malloc(size);

  if (mem == NULL)
  {
    throw "malloc failed";
  }

  int c = read(fh, mem, size);

  if (c != size)
  {
    throw "couldn't read entire file";
  }

  res = jsonParser::parse((char*)mem, size);

  free(mem);
  close(fh);

  return res;
}

#ifdef WITHOUT_MMAP
jsonValue* jsonParser::parse_file_mmap(const char* filename)
{
  return parse_file(filename);
}
#else
#include <sys/mman.h>
jsonValue* jsonParser::parse_file_mmap(const char* filename)
{
  int fh;
  void *mem;
  int size;
  jsonValue* res;

  fh = open(filename, O_RDONLY);
  if (fh < 0)
  {
    throw "cannot open file";
  }

  size = lseek(fh, 0, SEEK_END);
  if (size < 0)
  {
    throw "error";
  }
  lseek(fh, 0, SEEK_SET);

  mem = mmap(NULL, size, PROT_READ, MAP_SHARED, fh, 0);

  if (mem == MAP_FAILED)
  {
    throw "mmap failed";
  }

  res = jsonParser::parse((char*)mem, size);

  munmap(mem, size);
  close(fh);

  return res;
}
#endif
