/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2016 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#pragma once

#include <string>
#include "../core/configure.hpp"

namespace mango
{

	class FileObserver
	{
	protected:
		struct FileObserverState* m_state;

	public:
        enum Flags
        {
            CREATED     = 0x0001,
            DELETED     = 0x0002,
            MODIFIED    = 0x0004,
            FILE        = 0x0100,
            DIRECTORY   = 0x0200
        };

		FileObserver();
		virtual ~FileObserver();

        void start(const std::string& pathname);
        void stop();

        // Two kinds of events will be generated:
        //
        // 1: Change Notifications:
        //    Flags will be 0 and the filename empty; these are generated by systems
        //    which are unable to reliably track filesystem changes.
        //
        // 2: Extended Notifications:
        //    Flags will indicate what happened and the filename will indicate the affected file.
        //    Currently only Linux and Windows platforms are able to generate extended notifications.
        virtual void onEvent(uint32 flags, const std::string& filename) = 0;
	};

} // namespace mango
