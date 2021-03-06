/*
 * -*- coding: utf-8 -*- {{{
 * vim: set fenc=utf-8 ft=python sw=4 ts=4 sts=4 et:
 *
 * Copyright 2018, Kisensum.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Neither Kisensum, nor any of its employees, nor any jurisdiction or
 * organization that has cooperated in the development of these materials,
 * makes any warranty, express or implied, or assumes any legal liability
 * or responsibility for the accuracy, completeness, or usefulness or any
 * information, apparatus, product, software, or process disclosed, or
 * represents that its use would not infringe privately owned rights.
 * Reference herein to any specific commercial product, process, or service
 * by trade name, trademark, manufacturer, or otherwise does not necessarily
 * constitute or imply its endorsement, recommendation, or favoring by Kisensum.
 * }}}
 */

#ifndef PYDNP3_OPENPAL_CONTAINER_BUFFER_H
#define PYDNP3_OPENPAL_CONTAINER_BUFFER_H

#include <pybind11/pybind11.h>
#include <Python.h>

#include <openpal/container/Buffer.h>

#ifdef PYDNP3_OPENPAL

namespace py = pybind11;

void bind_Buffer(py::module &m)
{
    // ----- class: openpal::Buffer -----
    py::class_<openpal::Buffer, openpal::Array<uint8_t, uint32_t>>(m, "Buffer")

        .def(py::init<>())

        .def(
            py::init<uint32_t>(),
            ":type size: unsigned int",
            py::arg("size")
        )

        .def(
            py::init<const openpal::RSlice&>(),
            "Initialize with the exact size and contents of the view."
        )

        .def(
            "ToRSlice",
            &openpal::Buffer::ToRSlice
        )

        .def(
            "GetWSlice",
            (openpal::WSlice (openpal::Buffer::*)())
            &openpal::Buffer::GetWSlice
        )

        .def(
            "GetWSlice",
            (openpal::WSlice (openpal::Buffer::*)(uint32_t))
            &openpal::Buffer::GetWSlice,
            ":type maxSize: unsigned int",
            py::arg("maxSize")
        )

        .def(
            "__call__",
            (const uint8_t* (openpal::Buffer::*)() const)
            &openpal::Buffer::operator(),
            py::return_value_policy::automatic
        )

        .def(
            "__call__",
            (uint8_t* (openpal::Buffer::*)())
            &openpal::Buffer::operator(),
            py::return_value_policy::automatic
        );
}

#endif // PYDNP3_OPENPAL
#endif
