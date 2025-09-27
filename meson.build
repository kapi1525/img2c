project(
    'img2c',
    'cpp', 'c',
    version: '1.0.0',
    license: 'MIT',
    default_options: {
        'cpp_std':          'c++20',
        'c_std':            'c11',
        'default_library':  'static',
        'b_vscrt':          'static_from_buildtype',
        'warning_level':    '1',
    },
    meson_version: '>=1.2',
)




if host_machine.system() != 'windows'
    # static C++ standard library
    add_project_link_arguments(['-static-libstdc++', '-static-libgcc'], language: 'cpp')
endif



img2c = executable(
    'img2c',
    sources: files(
        'src/main.cpp',
    ),
    install: true,
)
