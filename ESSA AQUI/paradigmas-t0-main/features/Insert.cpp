/* SPDX-License-Identifer: MIT */

#if defined(GITHUB_WORKFLOW) && GITHUB_WORKFLOW == 1
    #include <catch2/catch.hpp>
#else
    #include <catch2/catch_test_macros.hpp>
#endif /* GITHUB_WORKFLOW */

#include "genarray.h"

SCENARIO("Inserir valores num array.", "[Insert]") {
    GIVEN("Um vetor com alguns itens") {
        GenericArray array;
        GenericArray_new(&array, sizeof(int));

        for (int i=0; i < 5; i++) {
            GenericArray_append(&array, &i);
        }

        WHEN ("Inserir um valor após o último elemento") {
	    int original_size = GenericArray_size(&array);
            int new_value = 10;
            int index = GenericArray_size(&array);
            int prev;
            GenericArray_get(&array, index-1, &prev);
            GenericArray_insert(&array, index, &new_value);

            THEN("O tamanho do array foi alterado em um elemento.") {
                REQUIRE(original_size + 1 == GenericArray_size(&array));
            }
            THEN("O último valor é o inserido.") {
                int value = 0;
                GenericArray_get(&array, index, &value);
                REQUIRE(value == new_value);
            }
            THEN("O valor anterior ao último, é o mesmo do último antes da alteração.") {
                int value = 0;
                GenericArray_get(&array, index-1, &value);

                REQUIRE(prev == value);
            }
        }
        
        WHEN ("Inserir um valor antes do primeiro elemento") {
            int original_size = GenericArray_size(&array);
            int new_value = 100;
            int next;
            GenericArray_get(&array, 0, &next);
            GenericArray_insert(&array, 0, &new_value);

            THEN("O tamanho do array foi alterado em um elemento.") {
                REQUIRE(original_size + 1 == GenericArray_size(&array));
            }
            THEN("O primeiro valor é o inserido.") {
                int value = 0;
                GenericArray_get(&array, 0, &value);

                REQUIRE(value == new_value);
            }
            THEN("O segundo valor é o primeiro anterior.") {
                int value = 0;
                GenericArray_get(&array, 1, &value);

                REQUIRE(next == value);
            }
        }

        WHEN ("Inserir um valor na antepenúltima posição.") {
            int original_size = GenericArray_size(&array);
            int new_value = 100;
            int index = GenericArray_size(&array)-3;
            int prev, next;
            GenericArray_get(&array, index - 1, &prev);
            GenericArray_get(&array, index, &next);
            GenericArray_insert(&array, index, &new_value);

            THEN("O tamanho do array foi alterado em um elemento.") {
                REQUIRE(original_size + 1 == GenericArray_size(&array));
            }
            THEN("Os valores anterior e próximo ainda são válidos.") {
                int value = 0;
                GenericArray_get(&array, index-1, &value);
                REQUIRE(value == prev);
                GenericArray_get(&array, index+1, &value);
                REQUIRE(value == next);
            }
            THEN("O valor inserido é o correto.") {
                int value = 0;
                GenericArray_get(&array, index, &value);
                REQUIRE(new_value == value);
            }
        }

        GenericArray_delete(&array);
    }
}

