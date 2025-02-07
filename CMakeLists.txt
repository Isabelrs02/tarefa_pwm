
cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Inicializa o pico_sdk a partir da localização instalada
# (isso pode vir do ambiente, cache do CMake etc)

# == NÃO EDITE AS LINHAS A SEGUIR para o funcionamento da Extensão Raspberry Pi Pico no VS Code ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

# Defina o tipo de placa do Raspberry Pi Pico
set(PICO_BOARD pico CACHE STRING "Board type")

# Inclui o SDK do Raspberry Pi Pico (deve estar antes do projeto)
include(pico_sdk_import.cmake)

# Defina o nome do projeto
project(tarefa_pwm C CXX ASM)

# Inicializa o SDK do Raspberry Pi Pico
pico_sdk_init()

# Adiciona o executável
add_executable(tarefa_pwm tarefa_pwm.c)

# Define o nome e a versão do programa
pico_set_program_name(tarefa_pwm "tarefa_pwm")
pico_set_program_version(tarefa_pwm "0.1")

# Modifique as linhas abaixo para habilitar/desabilitar a saída via UART/USB
pico_enable_stdio_uart(tarefa_pwm 1)  # Ativa UART
pico_enable_stdio_usb(tarefa_pwm 1)   # Ativa USB

# Adiciona a biblioteca padrão para o projeto
target_link_libraries(tarefa_pwm
        pico_stdlib
)

# Adiciona os diretórios de include necessários para o projeto
target_include_directories(tarefa_pwm PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Adiciona as bibliotecas de hardware necessárias (no seu caso, hardware_pwm e hardware_timer)
target_link_libraries(tarefa_pwm
        hardware_pwm   # Para controlar o PWM
        hardware_timer # Para utilizar temporizadores no Pico
)

# Adiciona saídas extras (como binário)
pico_add_extra_outputs(tarefa_pwm)
