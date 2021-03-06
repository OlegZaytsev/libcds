/*
    This file is a part of libcds - Concurrent Data Structures library

    (C) Copyright Maxim Khizhinsky (libcds.dev@gmail.com) 2006-2016

    Source code repo: http://github.com/khizmax/libcds/
    Download: http://sourceforge.net/projects/libcds/files/
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this
      list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     
*/

#ifndef CDSUNIT_PRINT_BRONSONAVLTREE_STAT_H
#define CDSUNIT_PRINT_BRONSONAVLTREE_STAT_H

#include <ostream>

namespace std {

    static inline ostream& operator <<( ostream& o, cds::container::bronson_avltree::empty_stat const& /*s*/ )
    {
        return o;
    }

    static inline ostream& operator <<(ostream& o, cds::container::bronson_avltree::stat<> const& s)
    {
        return o << "\nBronsonAVLTree statistics [cds::container::bronson_avltree::stat]:\n"
            << "\t\t             m_nFindSuccess: " << s.m_nFindSuccess.get()         << "\n"
            << "\t\t              m_nFindFailed: " << s.m_nFindFailed.get()          << "\n"
            << "\t\t               m_nFindRetry: " << s.m_nFindRetry.get()           << "\n"
            << "\t\t       m_nFindWaitShrinking: " << s.m_nFindWaitShrinking.get()   << "\n"
            << "\t\t           m_nInsertSuccess: " << s.m_nInsertSuccess.get()       << "\n"
            << "\t\t            m_nInsertFailed: " << s.m_nInsertFailed.get()        << "\n"
            << "\t\t     m_nRelaxedInsertFailed: " << s.m_nRelaxedInsertFailed.get() << "\n"
            << "\t\t             m_nInsertRetry: " << s.m_nInsertRetry.get()         << "\n"
            << "\t\t     m_nUpdateWaitShrinking: " << s.m_nUpdateWaitShrinking.get() << "\n"
            << "\t\t             m_nUpdateRetry: " << s.m_nUpdateRetry.get()         << "\n"
            << "\t\t m_nUpdateRootWaitShrinking: " << s.m_nUpdateRootWaitShrinking.get() << "\n"
            << "\t\t           m_nUpdateSuccess: " << s.m_nUpdateSuccess.get()       << "\n"
            << "\t\t          m_nUpdateUnlinked: " << s.m_nUpdateUnlinked.get()      << "\n"
            << "\t\t           m_nRemoveSuccess: " << s.m_nRemoveSuccess.get()       << "\n"
            << "\t\t            m_nRemoveFailed: " << s.m_nRemoveFailed.get()        << "\n"
            << "\t\t             m_nRemoveRetry: " << s.m_nRemoveRetry.get()         << "\n"
            << "\t\t          m_nExtractSuccess: " << s.m_nExtractSuccess.get()      << "\n"
            << "\t\t           m_nExtractFailed: " << s.m_nExtractFailed.get()       << "\n"
            << "\t\t     m_nRemoveWaitShrinking: " << s.m_nRemoveWaitShrinking.get() << "\n"
            << "\t\t m_nRemoveRootWaitShrinking: " << s.m_nRemoveRootWaitShrinking.get() << "\n"
            << "\t\t         m_nMakeRoutingNode: " << s.m_nMakeRoutingNode.get()     << "\n"
            << "\t\t           m_nDisposedValue: " << s.m_nDisposedValue.get()       << "\n"
            << "\t\t            m_nDisposedNode: " << s.m_nDisposedNode.get()        << "\n"
            << "\t\t          m_nExtractedValue: " << s.m_nExtractedValue.get()      << "\n"
            << "\t\t           m_nRightRotation: " << s.m_nRightRotation.get()       << "\n"
            << "\t\t            m_nLeftRotation: " << s.m_nLeftRotation.get()        << "\n"
            << "\t\t       m_nLeftRightRotation: " << s.m_nLeftRightRotation.get()   << "\n"
            << "\t\t       m_nRightLeftRotation: " << s.m_nRightLeftRotation.get()   << "\n"
            << "\t\t      m_nInsertRebalanceReq: " << s.m_nInsertRebalanceReq.get()  << "\n"
            << "\t\t      m_nRemoveRebalanceReq: " << s.m_nRemoveRebalanceReq.get()  << "\n"
            << "\t\tm_nRotateAfterRightRotation: " << s.m_nRotateAfterRightRotation.get() << "\n"
            << "\t\tm_nRemoveAfterRightRotation: " << s.m_nRemoveAfterRightRotation.get() << "\n"
            << "\t\tm_nDamageAfterRightRotation: " << s.m_nDamageAfterRightRotation.get() << "\n"
            << "\t\t m_nRotateAfterLeftRotation: " << s.m_nRotateAfterLeftRotation.get() << "\n"
            << "\t\t m_nRemoveAfterLeftRotation: " << s.m_nRemoveAfterLeftRotation.get() << "\n"
            << "\t\t m_nDamageAfterLeftRotation: " << s.m_nDamageAfterLeftRotation.get() << "\n"
            << "\t\t   m_nRotateAfterRLRotation: " << s.m_nRotateAfterRLRotation.get() << "\n"
            << "\t\t   m_nRemoveAfterRLRotation: " << s.m_nRemoveAfterRLRotation.get() << "\n"
            << "\t\t   m_nRotateAfterLRRotation: " << s.m_nRotateAfterLRRotation.get() << "\n"
            << "\t\t   m_nRemoveAfterLRRotation: " << s.m_nRemoveAfterLRRotation.get() << "\n";
    }
} //namespace std

#endif // #ifndef CDSUNIT_PRINT_ELLENBINTREE_STAT_H
