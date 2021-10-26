#include <stdio.h>

#define SIZE 8

typedef enum {
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
} Piece;

typedef enum {
    BLACK,
    WHITE
} Color;

typedef struct {
    Piece piece_type;
    Color color_type;
} Square;

Square board[SIZE][SIZE] = {
    {
        {ROOK, BLACK},
        {KNIGHT, BLACK},
        {BISHOP, BLACK},
        {KING, BLACK},
        {QUEEN, BLACK},
        {BISHOP, BLACK},
        {KNIGHT, BLACK},
        {ROOK, BLACK}
    },
    {
        {PAWN, BLACK},
        {PAWN, BLACK},
        {PAWN, BLACK},
        {PAWN, BLACK},
        {PAWN, BLACK},
        {PAWN, BLACK},
        {PAWN, BLACK},
        {PAWN, BLACK},
    },
    {
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
    },
    {
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
    },
    {
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
    },
    {
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
        {EMPTY, BLACK},
    },
    {
        {PAWN, WHITE},
        {PAWN, WHITE},
        {PAWN, WHITE},
        {PAWN, WHITE},
        {PAWN, WHITE},
        {PAWN, WHITE},
        {PAWN, WHITE},
        {PAWN, WHITE},
    },
    {
        {ROOK, WHITE},
        {KNIGHT, WHITE},
        {BISHOP, WHITE},
        {KING, WHITE},
        {QUEEN, WHITE},
        {BISHOP, WHITE},
        {KNIGHT, WHITE},
        {ROOK, WHITE}
    }
};
