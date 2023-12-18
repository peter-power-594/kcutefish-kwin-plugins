/*
 *   Copyright © 2021 Reion Wong <reionwong@gmail.com>
 *   Copyright © 2021 Reven Martin <revenmartin@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; see the file COPYING.  if not, write to
 *   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *   Boston, MA 02110-1301, USA.
 */

#ifndef ROUNDEDWINDOW_H
#define ROUNDEDWINDOW_H

#include <kwineffects.h>
#include <kwinglplatform.h>
#include <kwinglutils.h>

#include <xcb/xcb_atom.h>

class RoundedWindow : public KWin::Effect
{
    Q_OBJECT

public:
    enum DataRole {
        /* https://techbase.kde.org/Development/Tutorials/KWin/Effects/JS_API#KWin::EffectWindow */
        BaseRole = KWin::DataRole::WindowForceBlurRole + 100,
        WindowRadiusRole = BaseRole + 1,
        WindowClipPathRole = BaseRole + 2,
        WindowMaskTextureRole = BaseRole + 3,
        WindowDepthRole = BaseRole + 4
    };

    RoundedWindow(QObject *parent = nullptr, const QVariantList &args = QVariantList());
    ~RoundedWindow();

    static bool supported();
    static bool enabledByDefault();

    bool isMaximized(KWin::EffectWindow *w);

    void drawWindow(KWin::EffectWindow* w, int mask, const QRegion &region, KWin::WindowPaintData& data) override;

private:

    std::unique_ptr<KWin::GLShader> m_shader;
    std::unique_ptr<KWin::GLTexture> m_texure;

    xcb_atom_t m_netWMStateAtom = 0;
    xcb_atom_t m_netWMStateMaxHorzAtom = 0;
    xcb_atom_t m_netWMStateMaxVertAtom = 0;

    int m_frameRadius;
};

#endif
