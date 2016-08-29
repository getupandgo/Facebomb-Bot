{
  "targets": [
    {
      "target_name": "FaceBomber",
      "include_dirs": [
        "/usr/include/opencv",
      ],
      "link_settings": {
          "libraries": ["-lopencv_core", "-lopencv_highgui"]
      },
      "sources": [
        "./FaceBomberModule/addon.cc",
        "./FaceBomberModule/FaceBomber/FaceBomber.cpp",
        "./FaceBomberModule/wrapper.cc"
      ],
      "cflags": [
        "-std=c++11"
      ],
      "cflags_cc!": [
        "-fno-rtti",
        "-fno-exceptions"
      ]
    }
  ]
}