{
  'targets': [
    {
      'target_name': 'AM_SERVICE',
      'cflags': ['-std=c++11'],
      'type': 'executable',

      'include_dirs' : ['AM_Service/include'],
      'sources': ['AM_Service/main.cpp'],

      'conditions': [
        ['OS == "linux"', {
          'link_settings': {
            'libraries': ['-lpthread']
          },
        }],
      ],
    },
  ],
}
