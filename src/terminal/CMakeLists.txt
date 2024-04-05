# Copyright (c) 2024 Jakob Nixdorf
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required(VERSION 3.23)

# This component is the main executable of the project
set(COMPONENT_NAME ${PROJECT_NAME})

add_executable(${COMPONENT_NAME})

target_sources(
    ${COMPONENT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
)

target_link_libraries(
    ${COMPONENT_NAME}
    PRIVATE
        qtermwidget5
        ${PROJECT_NAME}::Settings
)

install(
    TARGETS ${COMPONENT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
