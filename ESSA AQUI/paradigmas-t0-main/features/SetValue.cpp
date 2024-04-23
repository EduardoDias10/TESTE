/* SPDX-License-Identifer: MIT */

#if defined(GITHUB_WORKFLOW) && GITHUB_WORKFLOW == 1
    #include <catch2/catch.hpp>
#else
    #include <catch2/catch_test_macros.hpp>
#endif /* GITHUB_WORKFLOW */

#include "genarray.h"

SCENARIO("Setar valores em posições específicas do array.", "[SetValue]") {
    GIVEN("Um vetor com alguns itens") {
        GenericArray array;
        GenericArray_new(&array, sizeof(int));

        for (int i=0; i < 5; i++) {
            GenericArray_append(&array, &i);
        }
        int original_size = GenericArray_size(&array);

        WHEN ("Ajusta-se o valor da posição 0") {
            int new_value = 10;
            GenericArray_set(&array, 0, &new_value);

            THEN("A posição 0 contém o novo valor.") {
                int value = 0;
                GenericArray_get(&array, 0, &value);

                REQUIRE(value == new_value);
            }
            THEN("O tamanho do array não foi alterado.") {
                REQUIRE(original_size == GenericArray_size(&array));
            }
        }

        WHEN ("Ajusta-se o valor da última posição") {
            int new_value = 1000;
            GenericArray_set(&array, original_size - 1, &new_value);

            THEN("A posição 0 contém o novo valor.") {
                int value = 0;
                GenericArray_get(&array, original_size - 1, &value);

                REQUIRE(value == new_value);
            }
            THEN("O tamanho do array não foi alterado.") {
                REQUIRE(original_size == GenericArray_size(&array));
            }
        }

        WHEN ("Ajusta-se o valor da terceira posição.") {
            int new_value = 100;
            GenericArray_set(&array, 2, &new_value);

            THEN("A posição 0 contém o novo valor.") {
                int value = 0;
                GenericArray_get(&array, 2, &value);

                REQUIRE(value == new_value);
            }
            THEN("O tamanho do array não foi alterado.") {
                REQUIRE(original_size == GenericArray_size(&array));
            }
        }

        GenericArray_delete(&array);
    }
}

