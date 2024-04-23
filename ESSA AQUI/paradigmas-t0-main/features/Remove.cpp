/* SPDX-License-Identifer: MIT */

#if defined(GITHUB_WORKFLOW) && GITHUB_WORKFLOW == 1
    #include <catch2/catch.hpp>
#else
    #include <catch2/catch_test_macros.hpp>
#endif /* GITHUB_WORKFLOW */

#include "genarray.h"

SCENARIO("Remover valores num array.", "[Remove]") {
    GIVEN("Um vetor com alguns itens") {
        GenericArray array;
        GenericArray_new(&array, sizeof(int));

        for (int i=0; i < 5; i++) {
            GenericArray_append(&array, &i);
        }

        WHEN ("Removerum o último elemento") {
	    int original_size = GenericArray_size(&array);
            GenericArray_remove(&array, original_size - 1);

            THEN("O tamanho do array foi reduzido em um elemento.") {
                REQUIRE(original_size - 1 == GenericArray_size(&array));
            }
            THEN("Os valores existentes continuam válidos.") {
                for (int i = 0; i < GenericArray_size(&array); i++) {
                    int value = -1;
                    GenericArray_get(&array, i, &value);
                    REQUIRE(i == value);
                }
            }
        }
        
        WHEN ("Remover o primeiro elemento") {
	    int original_size = GenericArray_size(&array);
            GenericArray_remove(&array, 0);

            THEN("O tamanho do array foi reduzido em um elemento.") {
                REQUIRE(original_size - 1 == GenericArray_size(&array));
            }
            THEN("Os valores existentes continuam válidos.") {
                for (int i = 0; i < GenericArray_size(&array); i++) {
                    int value = -1;
                    GenericArray_get(&array, i, &value);
                    REQUIRE(i+1 == value);
                }
            }
        }

        GenericArray_delete(&array);
    }
}

